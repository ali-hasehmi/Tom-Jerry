#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>

int main()
{

    if (!al_init())
    {
        fprintf(stderr, "[!]Couldn't initialize Allegro\n");
        exit(0);
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "[!] Couldn't Install Keyboard\n");
        exit(0);
    }
    if (!al_init_image_addon())
    {
        fprintf(stderr, "[!] Couldn't initialize image Addon\n");
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "[!] Could not initialize primitive addon\n");
    }
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    if (timer == NULL)
    {
        fprintf(stderr, "[!] Couldn't initialize the timer\n");
    }

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if (queue == NULL)
    {
        fprintf(stderr, "[!] Couldn't initialize the Event queue\n");
    }

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    if (display == NULL)
    {
        fprintf(stderr, "[!] Couldn't Create a Display\n");
    }

    ALLEGRO_FONT *font = al_create_builtin_font();
    if (font == NULL)
    {
        fprintf(stderr, "[!] Couldn't create teh builtin font\n");
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    ALLEGRO_BITMAP *home = al_load_bitmap("home.png");
    if (home == NULL)
    {
        fprintf(stderr, "[!] Could not Load the Home Image\n");
    }

    bool redraw;
    ALLEGRO_EVENT event;
    al_start_timer(timer);

    while (1)
    {
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return 0;
        }
        else if (event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {

            printf("%d ", event.keyboard.keycode);
        }
        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_text(font, al_map_rgb(0, 0, 0), 320, 240, 0, "hello world!");
            al_draw_bitmap(home, 320, 240, 0);
            al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(0, 0, 0));
            al_draw_filled_triangle(100, 100, 0, 270, 200, 270, al_map_rgb(100, 100, 100));
            al_draw_circle(250, 250, 50, al_map_rgb(100, 0, 0), 10);
            al_draw_line(0, 0, 100, 100, al_map_rgb(170, 0, 0), 2);
            // al_draw_tinted_bitmap(home,al_map_rgba_f(1.8,1.5,1.5,3),100,100,0);
            al_flip_display();
            redraw = false;
        }
    }
    al_destroy_bitmap(home);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}