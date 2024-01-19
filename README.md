# Projet_c_2ESGI

---

## Techno

---
![](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![](https://img.shields.io/badge/SDL2-FF0000?style=for-the-badge&logo=sdl&logoColor=white)
![](https://img.shields.io/badge/MySQL-00000F?style=for-the-badge&logo=mysql&logoColor=white)

## Installation

---

### Launch the db

```bash
docker compose -f docker-compose.test.yml up -d
```

### Install SDL2

```bash
git clone https://github.com/libsdl-org/SDL.git -b SDL2
cd SDL
mkdir build
cd build
../configure
make
sudo make install
```

### Install libmysql

```bash
sudo apt-get install libmysqlclient-dev
```

## Technical documentation

---

### Add Picture

---

in `game.c`

```c
SDL_Texture *cursor_texture = load_picture("../assets/resources/cursor.bmp", renderer);
```

and user this function in `display.c`

```c
void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);
```

### Add keyboard event

---

in `event.c` add key in `keyboard_manager` function your new event like this:

```c
void keyboard_manager(bool KEYS[323], Player *main_player, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    if (KEYS[(int) 'd'])
        move(1, main_player, level);
}
```

### Modify pieces

---

in `tetric_piece.c` we can edit the display of one piece with boolean logic like this :

```c
    switch (piece->type) {
        case 1: // white blue
            piece->x0 = true;
            piece->x1 = true;
            piece->x2 = true;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = false;
            piece->y3 = false;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = false;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
```

### Add tetris rules

---

in `tetre.c` wa can add function for tetris

if you want to add one display functionality add in `tetris_front.c`

### Save data in file

---

in `save.c`

- use `save(filename,data_in_str)` function for save data in file
- you have already `read_save(filename,board) function` to get the tetris board of the last game

### Click on button in the menu for example

---

in `menu.c` we verify if you click in the mousse button with this function

```c
if (!KEYS[323]) {
```

and we check if you are in the position of your button or image

```c
if ((x > 50 && x < 150) && (y > WINDOW_HEIGHT - 150 && y < WINDOW_HEIGHT - 50))
```

### Request mysql

---

in `connection.c` you can create other function for request mysql

- connect like this

```c
    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES *result;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;

    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);
```

- query like this

```c
    char query[100];
    sprintf(query, "SELECT game FROM PLAYERS  WHERE in_game= 2"); // TODO : remove this line
    if (mysql_query(&mysql, query)) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
```

- result like this

```c
    result = mysql_use_result(&mysql);
    int index_nb_other_player = 0;
    while ((row = mysql_fetch_row(result)) != NULL) {
```

- clear mysql

```c
mysql_close(&mysql);
```

### Linux function

---

in `linux.c` you can create other function for linux

for example, I add the function in windows like `atoi()`

### Channel list

---

in `arry.c` you can :

- init channel list like this

```c
    List  *channel_list = init_array()
```

- add element with

```c
insert_element_array(channel_list, element);
```

- remove first element with

```c
remove__element_array(channel_list);
```

## User Documentation

---

### Menu

---

- Click on the stat button on the left to access at the end of your last game
  ![](https://media.discordapp.net/attachments/1084071570567335956/1197964433838841967/image.png?ex=65bd2e52&is=65aab952&hm=389513f34a5a3d2d8b7f656ac57fa11535b4e31474d7c53519eb0edcb7016b26&=&format=webp&quality=lossless&width=623&height=468)
  ![](https://media.discordapp.net/attachments/1084071570567335956/1197965162569809930/image.png?ex=65bd2eff&is=65aab9ff&hm=17268ee7781a1c3237b91f917faf5f099a68b89af3edb97a3cb00df893d9b50a&=&format=webp&quality=lossless&width=623&height=468)

- Click on the play button to start a new game
  ![](https://media.discordapp.net/attachments/1084071570567335956/1197964506249314304/image.png?ex=65bd2e63&is=65aab963&hm=e556317ce144b356784b4138eb6b7b78d3a7f19d37d0f88ca1cc81603a57b492&=&format=webp&quality=lossless&width=623&height=468)
- if no user in game who wait 30 second for start a new game
- if user in waiting,you wait the rest of the waiting time with them
- if user in game, you wait the end of the game

### In game

---

![](https://media.discordapp.net/attachments/1084071570567335956/1197964544195166208/image.png?ex=65bd2e6c&is=65aab96c&hm=d24de65049e32ef99277f41c5041feef6c5fa410045f17d707d81163a4c05888&=&format=webp&quality=lossless&width=623&height=468)
- `s` to come down
- `d` to go right
- `q` to go left
- `a` to rotate
- `space` to go directly down

### Online functionality

---

![](https://media.discordapp.net/attachments/1084071570567335956/1197923873438584902/image.png?ex=65bd088b&is=65aa938b&hm=3b451c079dcf51c2314ba6e0a97bba110955ec504f8130ae1b29aaed3353cbfc&=&format=webp&quality=lossless&width=960&height=383)

- you can watch the board of other user in the left
- if you break a line, you add one piece in the board of other user
- if you are 10 piece, one line is add in your board