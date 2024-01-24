#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BALL_SIZE = 20;

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    // Initialize Allegro
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }

    // Create a display
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        fprintf(stderr, "Failed to create display!\n");
        return -1;
    }

    // Initialize Allegro primitives addon for basic shapes
    al_init_primitives_addon();

    // Install the keyboard
    al_install_keyboard();

    // Create an event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue!\n");
        al_destroy_display(display);
        return -1;
    }

    // Create a timer for animation
    timer = al_create_timer(1.0 / 60.0);
    if (!timer) {
        fprintf(stderr, "Failed to create timer!\n");
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
        return -1;
    }

    // Register event sources
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Start the timer
    al_start_timer(timer);

    // Ball properties
    float ball_x = SCREEN_WIDTH / 2.0;
    float ball_y = SCREEN_HEIGHT / 2.0;
    float ball_dx = 5.0;
    float ball_dy = 3.0;

    // Main game loop
    bool redraw = true;
    ALLEGRO_EVENT event;
    while (1) {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            // Update ball position
            ball_x += ball_dx;
            ball_y += ball_dy;

            // Bounce off the walls
            if (ball_x - BALL_SIZE / 2 < 0 || ball_x + BALL_SIZE / 2 > SCREEN_WIDTH) {
                ball_dx = -ball_dx;
            }
            if (ball_y - BALL_SIZE / 2 < 0 || ball_y + BALL_SIZE / 2 > SCREEN_HEIGHT) {
                ball_dy = -ball_dy;
            }

            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Draw the ball
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_filled_circle(ball_x, ball_y, BALL_SIZE / 2, al_map_rgb(255, 0, 0));

            // Flip the display
            al_flip_display();

            redraw = false;
        }
    }

    // Clean up
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
