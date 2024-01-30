#include "Characters.h"
#include "mouse.h"

grid_t *m_grid = NULL;
ALLEGRO_BITMAP *mouse_image1 = NULL;
ALLEGRO_BITMAP *mouse_image2 = NULL;
ALLEGRO_BITMAP *mouse_image3 = NULL;
ALLEGRO_BITMAP *mouse_image4 = NULL;

void init_mouse(grid_t *g)
{
    m_grid = g;
    mouse_image1 = al_load_bitmap("./asset/mouse/mouse1.png");
    if (mouse_image1 == NULL)
    {
        fprintf(stderr, "init_mouse(grid_t *): Could not load mouse1.png\n");
    }

    mouse_image2 = al_load_bitmap("./asset/mouse/mouse2.png");
    if (mouse_image2 == NULL)
    {
        fprintf(stderr, "init_mouse(grid_t *): Could not load mouse2.png\n");
    }

    mouse_image3 = al_load_bitmap("./asset/mouse/mouse3.png");
    if (mouse_image3 == NULL)
    {
        fprintf(stderr, "init_mouse(grid_t *): Could not load mouse3.png\n");
    }

    mouse_image4 = al_load_bitmap("./asset/mouse/mouse4.png");
    if (mouse_image4 == NULL)
    {
        fprintf(stderr, "init_mouse(grid_t *): Could not load mouse4.png\n");
    }
}

mouse_t *create_mouse(mice_t type)
{

    mouse_t *mouse = (mouse_t *)malloc(sizeof(mouse_t));
    mouse->is_alive = true;
    switch (type)
    {
    case ONE:
        mouse->speed = 1;
        mouse->point = 1;
        mouse->image = mouse_image1;
        break;
    case TWO:
        mouse->speed = 2;
        mouse->point = 2;
        mouse->image = mouse_image2;

        break;
    case THREE:
        mouse->speed = 3;
        mouse->point = 3;
        mouse->image = mouse_image3;

        break;
    case DEAD:
        mouse->speed = 0;
        mouse->point = 0;
        mouse->image = mouse_image4;
        break;
    default:
        fprintf(stderr, "create_mouse(mice_t ): invalid mouse type\n");
        break;
    }

    do
    {
        mouse->x = rand() % 15;
        mouse->y = rand() % 15;
    } while (m_grid->squares[mouse->y][mouse->x]->type != NOTHING);

    update_square(m_grid->squares[mouse->y][mouse->x], MOUSE, (void *)mouse);
    draw_image_at(mouse->image, m_grid, mouse->x, mouse->y);

    return mouse;
}

void update_mouse(mouse_t *mouse, int _x, int _y)
{
    update_square(m_grid->squares[mouse->y][mouse->x], NOTHING, (void *)NULL);
    mouse->x = _x;
    mouse->y = _y;
    update_square(m_grid->squares[mouse->y][mouse->x], MOUSE, (void *)mouse);
    draw_image_at(mouse->image, m_grid, mouse->x, mouse->y);
}

int destroy_mouse(mouse_t *mouse)
{
    free(mouse);
}

void eat_mouse(mouse_t* _m) {
    update_square(m_grid->squares[_m->y][_m->x], NOTHING, NULL);
}