#include "grid.h"

grid_t *create_grid(const int _grid_w, const int _grid_h, const int _square_width_size, const int _square_height_size)
{
    grid_t *g = (grid_t *)malloc(sizeof(grid_t));
    g->width = _grid_w;
    g->height = _grid_h;
    g->squares = (square_t ***)malloc(_grid_h * sizeof(square_t **));
    for (size_t i = 0; i < _grid_h; ++i)
    {
        g->squares[i] = (square_t **)malloc(_grid_w * sizeof(square_t *));
        for (size_t j = 0; j < _grid_w; ++j)
        {
            g->squares[i][j] = create_square(j * _square_width_size, i * _square_height_size,
                                             (j + 1) * _square_width_size + 1, (i + 1) * _square_height_size + 1);
        }
    }
    for (size_t i = 1; i < g->height-1; ++i)
    {
        for (size_t j = 1; j < g->width -1; ++j)
        {
            bool is_wall = rand() % 5;
            if (!is_wall)
            {
                int direction = rand() % 4;
                g->squares[i][j]->walls[direction] = 1;
                switch (direction)
                {
                case 0:
                    g->squares[i][j-1]->walls[2] =1;
                    break;
                case 1:
                    g->squares[i-1][j]->walls[3] =1;
                    break;
                case 2:
                    g->squares[i][j + 1]->walls[0] =1;
                    break;
                case 3:
                     g->squares[i+1][j]->walls[1] =1;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return g;
}

void destroy_grid(grid_t *g)
{
    for (size_t i = 0; i < g->height; ++i)
    {
        for (size_t j = 0; j < g->width; ++j)
        {
            destroy_square(g->squares[i][j]);
        }
        free(g->squares[i]);
    }
    free(g->squares);
    free(g);
}

void draw_grid(grid_t *g)
{
    for (size_t i = 0; i < g->height; ++i)
    {
        for (size_t j = 0; j < g->width; ++j)
        {
            draw_square(g->squares[i][j]);
        }
    }
}

void draw_image_at(ALLEGRO_BITMAP *image, grid_t *g, int _x, int _y)
{
    float scale_x, scale_y;
    printf("draw_image1.1\n");
    int image_width = al_get_bitmap_width(image);
    int image_height = al_get_bitmap_height(image);
    printf("draw_image1.2\n");
    scale_x = (float)SQUARE_WIDTH / image_width;
    // int image_height =al_get_bitmap_height(image);
    scale_y = (float)SQUARE_HEIGHT / image_height;
    printf("draw_image2\n");
    al_draw_scaled_bitmap(image, 0, 0, image_width, image_height,
                          g->squares[_y][_x]->x1, g->squares[_y][_x]->y1,
                          image_width * scale_x, image_width * scale_y, 0);
    printf("draw_image3\n");
}

// int main()
// {

//     al_init();
//     al_init_primitives_addon();
//     al_init_image_addon();

//     ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
//     ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

//     al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
//     al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
//     al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

//     ALLEGRO_DISPLAY *display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

//     al_register_event_source(queue, al_get_display_event_source(display));
//     al_register_event_source(queue, al_get_timer_event_source(timer));

//     square_t *s = create_square(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT);

//     grid_t *g = create_grid();

//     ALLEGRO_BITMAP *home = al_load_bitmap("home.png");
//     ALLEGRO_BITMAP *dog1 = al_load_bitmap("dog01.png");
//     ALLEGRO_BITMAP *dog2 = al_load_bitmap("dog02.png");
//     ALLEGRO_BITMAP *cat1 = al_load_bitmap("cat-1.png");
//     ALLEGRO_BITMAP *cat2 = al_load_bitmap("cat-2.png");
//     ALLEGRO_BITMAP *fish = al_load_bitmap("fish.png");
//     al_start_timer(timer);
//     while (1)
//     {
//         ALLEGRO_EVENT event;
//         al_wait_for_event(queue, &event);
//         switch (event.type)
//         {
//         case ALLEGRO_EVENT_DISPLAY_CLOSE:
//             return 1;
//             break;
//         case ALLEGRO_EVENT_TIMER:
//             al_clear_to_color(al_map_rgb(190, 156, 84));
//             draw_grid(g);
//             // draw_square(s);
//             draw_image_at(home, g, 7, 7);
//             draw_image_at(fish, g, 1, 0);
//             draw_image_at(dog1, g, 2, 3);
//             draw_image_at(dog2, g, 8, 5);
//             draw_image_at(cat1, g, 3, 2);
//             draw_image_at(cat2, g, 5, 7);

//             al_flip_display();
//             break;
//         default:
//             break;
//         }
//     }
//     destroy_grid(g);
//     return 0;
// }