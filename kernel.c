#include "kernel.h"
#include "cat.h"

grid_t *map_grid = NULL;
cat_t *players[2] = {NULL, NULL};
dog_t *dogs[4] = {NULL, NULL, NULL, NULL};
mouse_t *mice[18] = {NULL};
fish_t *fishes[10] = {NULL};

/// ALLEGRO STUFF
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *queue = NULL;
ALLEGRO_TIMER *timer = NULL;

void init_kernel()
{
    // initializing allegro
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    // Create Allegro Objects
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 30.0);

    // Set New Attributes
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    // Register Event Sources
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());

    // Create Display
    display = al_create_display(1200, 900);

    // Create Grid
    map_grid = create_grid(15, 15, 80, 60);

    // Initializing Objects
    init_cat(map_grid);
    init_dog(map_grid);
    init_fish(map_grid);
    init_mouse(map_grid);
    init_trap(map_grid);

    // Create Players
    for (int i = 0; i < 2; ++i)
    {
        players[i] = create_cat();
    }

    // Create Dogs
    for (int i = 0; i < 4; ++i)
    {
        dogs[i] = create_dog(i);
    }

    // Create Mice
    for (int i = 0; i < 4; i++)
    {
        mice[i] = create_mouse(THREE);
    }
    for (int i = 4; i < 10; i++)
    {
        mice[i] = create_mouse(TWO);
    }
    for (int i = 10; i < 18; i++)
    {
        mice[i] = create_mouse(ONE);
    }

    // Create Fishes
    for (int i = 0; i < 10; ++i)
    {
        fishes[i] = create_fish();
    }

    al_start_timer(timer);
}

void cleanup_kernel()
{
    al_stop_timer(timer);
    for (int i = 0; i < 10; ++i)
    {
        destroy_fish(fishes[i]);
    }
    for (int i = 0; i < 18; ++i)
    {
        destroy_mouse(mice[i]);
    }
    for (int i = 0; i < 4; ++i)
    {
        destroy_dog(dogs[i]);
    }
    for (int i = 0; i < 2; ++i)
    {
        destroy_cat(players[i]);
    }
    destroy_grid(map_grid);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);
}

void turn(cat_t *cat)
{
}

void game(grid_t *map)
{
    map_grid = map;
    cat_t *cat_one = create_cat();
    cat_t *cat_two = create_cat();
    dog_t *dogs[4]; // Weakest to Strongest:0->3
    mouse_t *mice[18];
    for (int i = 0; i < 4; i++)
        dogs[i] = create_dog(i);
    for (int i = 0; i < 4; i++)
    {
        mice[i] = create_mouse(THREE);
    }
    for (int i = 4; i < 10; i++)
    {
        mice[i] = create_mouse(TWO);
    }
    for (int i = 10; i < 18; i++)
    {
        mice[i] = create_mouse(ONE);
    }
    while (1)
    {
        turn(cat_one);
        turn(cat_two);
    }
}
