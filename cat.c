#include "cat.h"

cat_t* create_cat() {
    cat_t* cat = (cat_t*)malloc(sizeof(cat_t));
    cat->point = 0;
    cat->defense = 5;
    cat->attack = 2;
    cat->mouses = 0;
    for(int i = 0 ; i < 18 ; i++) {
        cat->mouse[i] = *(create_mouse(DEAD));
    }
}
void update_cat(cat_t* cat,state_t state,fish_t* fish) {
    switch (state) {
        case ONFISH:
            cat->defense +=fish->energy;
            break;
        case ONBONUS:
            cat->attack++;
            break;


    }
}
