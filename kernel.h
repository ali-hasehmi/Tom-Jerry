#ifndef TOM_JERRY_KERNEL_H
#define TOM_JERRY_KERNEL_H
#include "Characters.h"


void init_kernel();
void cleanup_kernel();
void updateDisplay();
void turn_player(cat_t* cat);
void game();


#endif //TOM_JERRY_KERNEL_H


