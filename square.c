#include "square.h"

square_t *create_square(int x1, int y1, int x2, int y2)
{
    square_t *s = (square_t *)malloc(sizeof(square_t));
    s->x1 = x1;
    s->y1 = y1;
    s->x2 = x2;
    s->y2 = y2;
    s->r = 160;
    s->g = 156;
    s->b = 101;
    return s;
}

void destroy_square(square_t *s)
{
    free(s);
}

void draw_square(square_t *s)
{
    al_draw_rectangle(s->x1, s->y1, s->x2, s->y2, al_map_rgb(s->r, s->g, s->b), 4);
}