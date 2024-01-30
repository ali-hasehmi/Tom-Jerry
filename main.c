#include "kernel.h"
#include <time.h>

int main(){

    srand(time(NULL));
    printf("main1\n");
    init_kernel();
    printf("main2\n");
    game();
    printf("main3\n");


}