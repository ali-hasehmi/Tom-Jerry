#ifndef GRID_H
#define GRID_H

#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 1200

#define SQUARE_HEIGHT DISPLAY_HEIGHT / 15
#define SQUARE_WIDTH DISPLAY_WIDTH / 15

#include "square.h"

typedef struct grid
{
    square_t ***squares;
    int width;
    int height;
} grid_t;


grid_t *create_grid(int _grid_w,int _grid_h,int _square_width_size,int _square_height_size);

void destroy_grid(grid_t *g);

void draw_grid(grid_t *g);

void draw_image_at(ALLEGRO_BITMAP *image, grid_t *g, int _x, int _y);

bool isValid(grid_t *g,int _x1,int _y1,int _x2,int _y2);

#endif // GRID_H