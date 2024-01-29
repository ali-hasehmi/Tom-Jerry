#include "Characters.h"

mouse_t* create_mouse(mice_t type) {
    mouse_t* mouse =  (mouse_t*)malloc(sizeof(mouse_t));
    switch (type) {
        case ONE:
            mouse->speed = 1;
            mouse->point = 1;
            break;
        case TWO:
            mouse->speed = 2;
            mouse->point = 2;
            break;
        case THREE:
            mouse->speed = 3;
            mouse->point = 3;
            break;
        case DEAD:
            mouse->speed = 0;
            mouse->point = 0;
            break;
    }
    mouse->x = rand()%15;
    mouse->y = rand()%15;
    return mouse;
}

void update_mouse(mouse_t* mouse,int _x,int _y) {
    mouse->x = _x;
    mouse->y = _y;
}

int destroy_mouse(mouse_t* mouse) {
    free(mouse);
}