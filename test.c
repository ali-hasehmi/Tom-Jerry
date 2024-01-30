#include "grid.h"
#include <stdio.h>
#include "dog.h"
#include "fish.h"
#include "trap.h"
#include "mouse.h"
#include "cat.h"

int main()
{

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);

    ALLEGRO_DISPLAY *display = al_create_display(1200, 900);

    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    grid_t *g = create_grid(15, 15, 80, 60);
    init_dog(g);
    init_fish(g);
    init_trap(g);
    init_mouse(g);
    init_cat(g);

    dog_t *b = create_dog(BULLDOG);
    dog_t *p = create_dog(PITBULL);
    dog_t *s = create_dog(SHEPHERD);
    dog_t *br = create_dog(BULLDOGJR);
    fish_t *f = create_fish();
    fish_t *f2 = create_fish();
    trap_t *trap = create_trap();
    mouse_t *m1 = create_mouse(ONE);
    mouse_t *m2 = create_mouse(TWO);
    mouse_t *m3 = create_mouse(THREE);
    cat_t *cat = create_cat();
    al_start_timer(timer);
    printf("here\n");
    int i = 0, j = 0;
    int dx = 0, dy = 0;
    bool redraw = false;
    while (1)
    {
        ALLEGRO_EVENT e;
        al_wait_for_event(queue, &e);
        switch (e.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return 0;
            break;
        case ALLEGRO_EVENT_TIMER:
            redraw = true;

            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (e.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                dx = 1;
                dy = 0;
            }
            if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                dx = 0;
                dy = 1;
            }
            if (e.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                dx = -1;
                dy = 0;
            }
            if (e.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                dx = 0;
                dy = -1;
            }
            // if(e.keyboard.keycode == ALLEGRO_KEY_RIGHT){
            //     dx = 1;
            //     dy = 0;
            // }
            move_cat(cat, dx, dy);
            break;
        default:
            printf("NOTHING\n");
            break;
        }
        if (redraw && al_is_event_queue_empty(queue))
        {
            printf("this is\n");
            al_clear_to_color(al_map_rgb(190, 156, 84));
            al_draw_line(0, 1, 1200, 1, al_map_rgb(147, 154, 70), 25);
            al_draw_line(0, 1, 0, 900, al_map_rgb(147, 154, 70), 25);
            al_draw_line(0, 900, 1200, 900, al_map_rgb(147, 154, 70), 25);
            al_draw_line(1200, 1, 1200, 900, al_map_rgb(147, 154, 70), 25);
            // update_square(g->squares[4][4],TRAP,NULL);
            // printf("1\n");
            move_dog(b);
            // update_dog(b, ++i, ++j);
            // printf("2\n");
            move_dog(p);
            // update_dog(p, (i + 2) / 3, (j + 1) / 2);
            // printf("3\n");
            move_dog(s);
            // update_dog(s, (i + 1) / 4, (j + 1) / 9);
            // printf("4\n");
            move_dog(br);
            // update_dog(br, (i + 6) / 8, (j + 1) / 5);
            // printf("5\n");
            // update_fish(f);
            // printf("6\n");
            update_fish(f2);
            // printf("7\n");
            // update_trap(trap, rand() % 3);
            // printf("8\n");
            // int x = rand() % 1 + 1;
            // update_mouse(m1, m1->x + x, m1->y + x - 1);
            // update_mouse(m2, m2->x + x - 1, m2->y + x);
            // update_mouse(m3, m3->x + x, m3->y + x - 1);
            update_cat(cat, cat->x, cat->y);
            draw_grid(g);
            printf("9\n");
            al_flip_display();
        }
    }
    destroy_grid(g);
    system("pause");
    return 0;
}