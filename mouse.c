#include "mouse.h"
#include <math.h>

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
    mouse->actions = mouse->speed;

    do
    {
        mouse->x = rand() % 15;
        mouse->y = rand() % 15;
    } while (m_grid->squares[mouse->y][mouse->x]->type != NOTHING);

    update_square(m_grid->squares[mouse->y][mouse->x], MOUSE, (void *)mouse);
    draw_image_at(mouse->image, m_grid, mouse->x, mouse->y);

    return mouse;
}

mouse_t *create_mouse_with_xy(int _x, int _y)
{
    mouse_t *mouse = (mouse_t *)malloc(sizeof(mouse_t));
    mouse->is_alive = false;
    mouse->x = _x;
    mouse->y = _y;
    mouse->type = DEAD;
    return mouse;
}

void update_mouse(mouse_t *mouse, int _x, int _y)
{
    if (!mouse->is_alive)
    {
        return;
    }
    if (mouse->x == _x && mouse->y == _y)
    {
        update_square(m_grid->squares[mouse->y][mouse->x], MOUSE, (void *)mouse);
        draw_image_at(mouse->image, m_grid, mouse->x, mouse->y);
        return;
    }
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

void eat_mouse(mouse_t *_m)
{
    _m->is_alive = false;
    update_square(m_grid->squares[_m->y][_m->x], NOTHING, NULL);
}

float distance(mouse_t *mouse, mouse_t *cat)
{
    printf("distance(mouse_t *, mouse_t *) Called\n");
    printf("distance(mouse_t *, mouse_t *): mouse->x=%d, mouse->y =%d, cat->x=%d, cat->y=%d\n",
           mouse->x, mouse->y, cat->x, cat->y);
    float res = powf((mouse->x - cat->x), 2) + powf((mouse->y - cat->y), 2);
    return sqrtf(res);
}

int move_mouse(mouse_t *_m, mouse_t *cats[2])
{
    if (!_m->is_alive)
    {
        return -1;
    }
    int dir[8][2] = {
        {1, 0},   // RIGHT
        {-1, 0},  // LEFT
        {0, 1},   // DOWN
        {0, -1},  // UP
        {1, 1},   // RIGHT_DOWN
        {1, -1},  // RIGHT_UP
        {-1, -1}, // LEFT_UP
        {-1, 1}   // LEFT_DOWN
    };
    int new_x, new_y;
    float distance_with_cat1 = distance(_m, cats[0]);
    float distance_with_cat2 = distance(_m, cats[1]);
    mouse_t *tmp_mouse = NULL;
    int cnt = 10;
    while(1) {
        if(cnt-- < 0) break;
        int rand_num = rand() % 8;
        new_x = _m->x + dir[rand_num][0];
        new_y = _m->y + dir[rand_num][1];
        tmp_mouse = create_mouse_with_xy(new_x, new_y);
        if((!isValid(m_grid, _m->x, _m->y, new_x, new_y)))
            continue;
        else if(((m_grid->squares[new_y][new_x]->type == CAT) || (m_grid->squares[new_y][new_x]->type == MOUSE)))
            continue;
        else if(((distance(tmp_mouse, cats[0]) >= distance_with_cat1) && (distance(tmp_mouse, cats[1]) >= distance_with_cat2)))
            break;


    }
    do {
        printf("do while for infinite loop");
        int rand_num = rand() % 8;
        new_x = _m->x + dir[rand_num][0];
        new_y = _m->y + dir[rand_num][1];
    }while((!isValid(m_grid, _m->x, _m->y, new_x, new_y)));

    update_mouse(_m, new_x, new_y);
    free(tmp_mouse);
}

void release_mouse(mouse_t *mouse)
{
    mouse->is_alive = true;
    int new_x;
    int new_y;
    do
    {
        new_x = rand() % 15;
        new_y = rand() % 15;
    } while (m_grid->squares[new_y][new_x]->type != NOTHING || ((new_x == 7) && (new_y == 7)));
    mouse->x = new_x;
    mouse->y = new_y;
    update_mouse(mouse, new_x, new_y);
}
