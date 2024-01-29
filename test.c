#include "grid.h"
#include <stdio.h>
#include "dog.h"
#include "fish.h"

int main()
{

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 );

    ALLEGRO_DISPLAY *display = al_create_display(1200, 900);

    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));
    grid_t *g = create_grid(15, 15, 80, 60);
    init_dog(g);
    init_fish(g);
    dog_t *d = create_dog(BULLDOG);
    fish_t *f = create_fish();
    fish_t *f2 = create_fish();
    al_start_timer(timer);
    printf("here\n");
    int i = 0, j = 0;
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
            printf("this is\n");
            al_clear_to_color(al_map_rgb(255, 255, 255));
            //update_square(g->squares[4][4],TRAP,NULL);
            update_dog(d,++i,++j);
            update_fish(f,true);
            update_fish(f2,true);
            draw_grid(g);
            al_flip_display();
            break;
        default:
            printf("NOTHING\n");
            break;
        }
    }
    destroy_grid(g);
    system("pause");
    return 0;
}