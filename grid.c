#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 1200

#define SQUARE_HEIGHT DISPLAY_HEIGHT / 15
#define SQUARE_WIDTH DISPLAY_WIDTH / 15

typedef struct square
{

    int x1, y1;
    int x2, y2;
    int r, g, b;

} square_t;

typedef struct grid
{
    square_t *squares[SQUARE_HEIGHT][SQUARE_WIDTH];
} grid_t;

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

grid_t *create_grid()
{
    grid_t *g = (grid_t *)malloc(sizeof(grid_t));
    for (size_t i = 0; i < 15; ++i)
    {
        for (size_t j = 0; j < 15; ++j)
        {
            g->squares[i][j] = create_square(j * SQUARE_WIDTH, i * SQUARE_HEIGHT, (j + 1) * SQUARE_WIDTH, (i + 1) * SQUARE_HEIGHT);
        }
    }
    return g;
}

void destroy_grid(grid_t *g)
{
    for (size_t i = 0; i < 15; ++i)
    {
        for (size_t j = 0; j < 15; ++j)
        {
            destroy_square(g->squares[i][j]);
        }
    }
    free(g);
}


void draw_grid(grid_t *g)
{
    for (size_t i = 0; i < 15; ++i)
    {
        for (size_t j = 0; j < 15; ++j)
        {
            draw_square(g->squares[i][j]);
        }
    }
}

void draw_image_at(ALLEGRO_BITMAP *image, grid_t *g, int _x, int _y)
{
    float scale_x, scale_y;
    int image_width = al_get_bitmap_width(image);
    int image_height = al_get_bitmap_height(image);
    scale_x = (float)SQUARE_WIDTH / image_width;
    // int image_height =al_get_bitmap_height(image);
    scale_y = (float)SQUARE_HEIGHT / image_height;
    al_draw_scaled_bitmap(image, 0, 0, image_width, image_height,
                          g->squares[_y][_x]->x1, g->squares[_y][_x]->y1,
                          image_width * scale_x, image_width * scale_y, 0);
}


int main()
{

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY *display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    square_t *s = create_square(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT);

    grid_t *g = create_grid();

    ALLEGRO_BITMAP *home = al_load_bitmap("home.png");
    ALLEGRO_BITMAP *dog1 = al_load_bitmap("dog01.png");
    ALLEGRO_BITMAP *dog2 = al_load_bitmap("dog02.png");
    ALLEGRO_BITMAP *cat1 = al_load_bitmap("cat-1.png");
    ALLEGRO_BITMAP *cat2 = al_load_bitmap("cat-2.png");
    ALLEGRO_BITMAP *fish = al_load_bitmap("fish.png");
    al_start_timer(timer);
    while (1)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return 1;
            break;
        case ALLEGRO_EVENT_TIMER:
            al_clear_to_color(al_map_rgb(190, 156, 84));
            draw_grid(g);
            // draw_square(s);
            draw_image_at(home, g, 7, 7);
            draw_image_at(fish, g, 1, 0);
            draw_image_at(dog1, g, 2, 3);
            draw_image_at(dog2, g, 8, 5);
            draw_image_at(cat1, g, 3, 2);
            draw_image_at(cat2, g, 5, 7);

            al_flip_display();
            break;
        default:
            break;
        }
    }
    destroy_grid(g);
    return 0;
}