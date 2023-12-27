# Projet_c_2ESGI

---

## Table of Contents

---

- [Projet_c_2ESGI](#projet_c_2esgi)
  - [Table of Contents](#table-of-contents)
  - [Techno](#techno)
  - [Assets](#assets)
  - [Installation](#installation)
    - [Launch the server](#launch-the-server)
    - [Compile game c code (on windows)](#compile-game-c-code-on-windows)
  - [Documentation](#documentation)
      - [Add Picture](#add-picture)
      - [Add keyboard event](#add-keyboard-event)



## Techno

---
![](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)





## Assets

---

#### Assets have been generated with https://scribblediffusion.com/


## Installation

---

### Launch the db
```bash
docker compose -f docker-compose.test.yml up -d
```

### Compile game c code (on windows)
```bash
gcc -o game.exe game.c
```



## Documentation

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

---