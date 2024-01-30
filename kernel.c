#include "kernel.h"
grid_t* map_grid = NULL;


void turn(cat_t* cat) {

}

void game(grid_t* map) {
    map_grid = map;
    cat_t* cat_one = create_cat();
    cat_t* cat_two = create_cat();
    dog_t* dogs[4];//Weakest to Strongest:0->3
    mouse_t* mice[18];
    for(int i = 0 ; i < 4 ; i++)
        dogs[i] = create_dog(i);
    for(int i = 0 ; i < 4 ; i++) {
        mice[i] = create_mouse(THREE);
    }
    for(int i = 4 ; i < 10 ; i++) {
        mice[i] = create_mouse(TWO);
    }
    for(int i = 10 ; i < 18 ; i++) {
        mice[i] = create_mouse(ONE);
    }
    while(1) {
        turn(cat_one);
        turn(cat_two);

    }

}
