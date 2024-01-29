#include "Characters.h"

mouse_t* create_mouse(int _speed,int _point) {
    mouse_t* mouse =  (mouse_t*)malloc(sizeof(mouse_t));
    mouse->speed = _speed;
    mouse->point = _point;
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