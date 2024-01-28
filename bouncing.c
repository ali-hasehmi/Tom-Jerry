#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <stdlib.h>
#include <stdio.h>

#define DISPLAY_WIDTH 1200
#define DISPLAY_HEIGHT 900
#define MAX_BOUNCER_SPEED 10
#define MIN_BOUNCER_SPEED 5

typedef struct square
{
    int r, g, b;
    int x1;
    int x2;
    int y1;
    int y2;
    ALLEGRO_BITMAP *pic;
} square_t;

void draw_square(square_t *s)
{
    al_draw_rectangle(s->x1, s->y1, s->x2, s->y2, al_map_rgb(s->r, s->g, s->b), 1);
//     if(s->pic != NULL){
//         float scale_x = (float)(s->x2-s->x1)/al_get_bitmap_width(s->pic);
//         float scale_y = (float)(s->y2-s->y1)/al_get_bitmap_height(s->pic);
//     al_draw_scaled_bitmap(s->pic,0,0,al_get_bitmap_width(s->pic),al_get_bitmap_height(s->pic),10,10,80*scale_x,60 *scale_y,0);
//    // al_draw_bitmap(s->pic, (s->x2 - s->x1) / 2, (s->y2 - s->y1) / 2, 0);
//     }
}
square_t *create_square(int x1, int y1, int x2, int y2, const char *pic_path)
{
    square_t *s = (square_t *)malloc(sizeof(create_square));
    s->r = 0;
    s->g = 0;
    s->b = 0;
    s->pic = al_load_bitmap(pic_path);
    s->x1 = x1;
    s->x2 = x2;
    s->y1 = y1;
    s->y2 = y2;
    return s;
}
typedef struct bouncer
{
    int x;
    int y;
    int dx;
    int dy;
} bouncer_t;

void update_bouncer(bouncer_t *b)
{
    printf("%d %d\n", b->x, b->y);
    b->x += b->dx;
    b->y += b->dy;
    if (b->x < 0)
    {
        b->dx *= -1;
        // b->x *=-1;
    }
    if (b->y < 0)
    {
        // b->y *= -1;
        b->dy *= -1;
    }
    if (b->x > DISPLAY_WIDTH)
    {
        b->dx *= -1;
    }
    if (b->y > DISPLAY_HEIGHT)
    {
        b->dy *= -1;
    }
}

bouncer_t *create_random_bounder()
{
    bouncer_t *b = (bouncer_t *)malloc(sizeof(bouncer_t));
    b->x = rand() % DISPLAY_WIDTH;
    b->y = rand() % DISPLAY_HEIGHT;
    b->dx = rand() % (MAX_BOUNCER_SPEED - MIN_BOUNCER_SPEED + 1) + MIN_BOUNCER_SPEED;
    b->dy = rand() % (MAX_BOUNCER_SPEED - MIN_BOUNCER_SPEED + 1) + MIN_BOUNCER_SPEED;
    return b;
}

void delete_bouncer(bouncer_t *b)
{
    free(b);
}
int main()
{

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY *main_display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(main_display));
    square_t *s = create_square(0, 0, 80, 60, "home.png");
    al_start_timer(timer);
    bouncer_t *bouncer[4];
    for (int i = 0; i < 4; ++i)
    {
        bouncer[i] = create_random_bounder();
    }
    // Game Loop
    while (1)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return 0;
            break;
        case ALLEGRO_EVENT_TIMER:
            al_clear_to_color(al_map_rgb(255, 255, 255));
            for (int i = 0; i < 4; ++i)
            {
                update_bouncer(bouncer[i]);
            }
            for (int i = 0; i < 4; ++i)
            {
                al_draw_filled_circle(bouncer[i]->x, bouncer[i]->y, 25, al_map_rgb(150, 0, 0));
            }
            draw_square(s);
            al_flip_display();
        default:
            break;
        }
    }
    al_destroy_display(main_display);

    return 0;
}