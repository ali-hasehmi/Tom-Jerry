#include "trap.h"
#include "Characters.h"

ALLEGRO_BITMAP *trap_image = NULL;
grid_t *t_grid = NULL;

void init_trap(grid_t *g)
{
    t_grid = g;
    trap_image = al_load_bitmap("./asset/trap/trap.png");
    if (trap_image == NULL)
    {
        fprintf(stderr, "init_trap(grid_t *):Could not load trap image\n");
    }
}

trap_t *create_trap()
{
    trap_t *trap = (trap_t *)malloc(sizeof(trap_t));
    trap->is_reveal = false;
    trap->image = trap_image;
    do
    {
        trap->x = rand() % 15;
        trap->y = rand() % 15;
    } while (!set_square_as_trap(t_grid->squares[trap->y][trap->x]));
    t_grid->squares[trap->y][trap->x]->trap = trap;
    return trap;
}

void update_trap(trap_t *t)
{
    //t->is_reveal = _is_reveal;
    if (!t->is_reveal)
    {
        return;
    }
    printf("update_trap\n");
    printf("%d %d %p\n",t->x,t->y,t->image);
    draw_image_at(t->image, t_grid, t->x, t->y);
}

void destroy_trap(trap_t *t)
{
    free(t);
}
