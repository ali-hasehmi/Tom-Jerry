#include "kernel.h"
#include "cat.h"
#include "trap.h"

#include <windows.h>

grid_t *map_grid = NULL;
cat_t *players[2] = {NULL, NULL};
dog_t *dogs[4] = {NULL, NULL, NULL, NULL};
mouse_t *mice[18] = {NULL};
fish_t *fishes[10] = {NULL};
trap_t *traps[8] = {NULL};
bonus_t *bonus[8] = {NULL};

/// ALLEGRO STUFF
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *font = NULL;

void init_kernel()
{
    // initializing allegro
    printf("phase 1\n");
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    // Create Allegro Objects
    printf("phase 2\n");
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 30.0);

    // Set New Attributes
    printf("phase 3\n");
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    // Create Display
    printf("phase 5\n");
    display = al_create_display(1800, 900);
    // Crate Font
    font = al_create_builtin_font();
    // Register Event Sources
    printf("phase 4.1\n");
    al_register_event_source(queue, al_get_display_event_source(display));
    printf("phase 4.2\n");
    al_register_event_source(queue, al_get_timer_event_source(timer));
    printf("phase 4.3\n");
    al_register_event_source(queue, al_get_keyboard_event_source());

    // Create Grid
    printf("phase 6\n");
    map_grid = create_grid(15, 15, 80, 60);

    // Initializing Objects
    printf("phase 7\n");
    init_cat(map_grid);
    init_dog(map_grid);
    init_fish(map_grid);
    init_mouse(map_grid);
    init_trap(map_grid);
    init_bonus(map_grid);

    // Create Players
    printf("phase 8\n");
    for (int i = 0; i < 2; ++i)
    {
        players[i] = create_cat(i);
    }

    printf("phase 9\n");
    // Create Dogs
    for (int i = 0; i < 4; ++i)
    {
        dogs[i] = create_dog(i);
    }

    printf("phase 10\n");
    // Create Mice
    for (int i = 0; i < 4; i++)
    {
        mice[i] = create_mouse(THREE);
    }
    printf("phase 11\n");
    for (int i = 4; i < 10; i++)
    {
        mice[i] = create_mouse(TWO);
    }
    printf("phase 12\n");
    for (int i = 10; i < 18; i++)
    {
        mice[i] = create_mouse(ONE);
    }

    printf("phase 13\n");
    // Create Fishes
    for (int i = 0; i < 10; ++i)
    {
        fishes[i] = create_fish();
    }

    // Create Trap
    for (int i = 0; i < 8; ++i)
    {
        traps[i] = create_trap();
    }

    // Create Bonus
    for (int i = 0; i < 8; ++i)
    {
        bonus[i] = create_bonus();
    }

    printf("phase 14\n");
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

void updateDisplay()
{
    printf("update1\n");
    al_clear_to_color(al_map_rgb(190, 156, 84));
    al_draw_line(0, 1, 1200, 1, al_map_rgb(147, 154, 70), 25);
    al_draw_line(0, 1, 0, 900, al_map_rgb(147, 154, 70), 25);
    al_draw_line(0, 900, 1200, 900, al_map_rgb(147, 154, 70), 25);
    al_draw_line(1200, 1, 1200, 900, al_map_rgb(147, 154, 70), 25);
    printf(" Update2\n");

    for (int i = 0; i < 2; ++i)
    {
        update_cat(players[i], players[i]->x, players[i]->y);
    }
    for (int i = 0; i < 4; ++i)
    {
        update_dog(dogs[i], dogs[i]->x, dogs[i]->y);
    }
    for (int i = 0; i < 18; ++i)
    {
        update_mouse(mice[i], mice[i]->x, mice[i]->y);
    }
    for (int i = 0; i < 10; ++i)
    {
        update_fish(fishes[i]);
    }
    for (int i = 0; i < 8; ++i)
    {
        update_trap(traps[i]);
    }
    for (int i = 0; i < 8; ++i)
    {
        update_bonus(bonus[i]);
    }
    draw_grid(map_grid);
    al_draw_textf(font, al_map_rgb(0, 0, 0),
                  map_grid->height * 80 + 10, 10, 0, "Player1 - defense: %d - attack: %d - point: %d", players[0]->defense, players[0]->defense,players[0]->point);
    al_flip_display();
}

void turn_player(cat_t *cat)
{
    if (cat->is_limited)
    {
        printf("is limited\n");
        cat->is_limited--;
        return;
    }
    printf("1\n");
    bool redraw = false;
    int dx = 0, dy = 0;
    while (cat->actions > 0 && !cat->is_limited)
    {
        ALLEGRO_EVENT e;
        al_wait_for_event(queue, &e);
        switch (e.type)
        {
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
            if (!move_cat(cat, dx, dy))
            {
                redraw = true;
            }
            break;
        default:
            //            fprintf(stderr, "Invalid Key INPUT\n");
            break;
        }
        if (redraw)
        {
            updateDisplay();
            redraw = false;
        }
    }
    cat->actions = 3;
}

void turn_dog(dog_t *dog)
{
    if (!dog->is_alive)
    {
        return;
    }

    while (dog->actions > 0)
    {
        Sleep(rand() % 1000 + 500);
        move_dog(dog);
        updateDisplay();
        dog->actions--;
    }
    dog->actions = dog->speed;
}

void turn_mouse(mouse_t *mouse)
{
    if (!mouse->is_alive)
    {
        return;
    }
    mouse_t *cats[2] = {NULL};
    cats[0] = create_mouse_with_xy(players[0]->x, players[0]->y);
    cats[1] = create_mouse_with_xy(players[1]->x, players[1]->y);
    printf("mouse 1");
    while (mouse->actions > 0)
    {
        Sleep(rand() % 1000 + 100);
        move_mouse(mouse, cats);
        updateDisplay();
        mouse->actions--;
    }
    mouse->actions = mouse->speed;
    free(cats[0]);
    free(cats[1]);
}

void game()
{
    updateDisplay();
    bool is_done = false;
    while (!is_done)
    {
        for (int i = 0; i < 2; ++i)
        {
            turn_player(players[i]);
        }
        for (int i = 0; i < 4; ++i)
        {
            turn_dog(dogs[i]);
        }
        for (int i = 0; i < 18; i++)
        {
            turn_mouse(mice[i]);
        }
    }
}
