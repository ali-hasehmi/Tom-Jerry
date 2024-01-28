#include <allegro5/allegro.h>
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

void draw_square(square_t *s)
{
    al_draw_rectangle(s->x1, s->y1, s->x2, s->y2, al_map_rgb(s->r, s->g, s->b), 4);
}
int main()
{

    al_init();
    al_init_primitives_addon();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    ALLEGRO_DISPLAY *display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    square_t *g[SQUARE_HEIGHT][SQUARE_WIDTH];
    square_t *s = create_square(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT);

    for (size_t i = 0; i < SQUARE_HEIGHT ; ++i)
    {
        for (size_t j = 0; j < SQUARE_WIDTH ; ++j)
        {
            g[i][j] = create_square(j * SQUARE_WIDTH, i * SQUARE_HEIGHT, (j + 1) * SQUARE_WIDTH, (i + 1) * SQUARE_HEIGHT);
        }
    }

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
            for (size_t i = 0; i < SQUARE_HEIGHT; ++i)
            {
                for (size_t j = 0; j < SQUARE_WIDTH ; ++j)
                {
                    draw_square(g[i][j]);
                }
            }
            //draw_square(s);
            al_flip_display();
            break;
        default:
            break;
        }
    }
    return 0;
}