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


## Documentation tech

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
