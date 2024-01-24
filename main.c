#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int GRID_SIZE = 15;
const int SQUARE_SIZE = SCREEN_WIDTH / GRID_SIZE;

// Structure representing an object (e.g., cat, mouse, dog)
struct GameObject {
    int health;
    int attack;
    ALLEGRO_BITMAP* image; // Image for the object
};

// Function to draw a square on the grid
void drawSquare(ALLEGRO_DISPLAY* display, int row, int col, ALLEGRO_COLOR color) {
    al_draw_filled_rectangle(col * SQUARE_SIZE, row * SQUARE_SIZE,
                             (col + 1) * SQUARE_SIZE, (row + 1) * SQUARE_SIZE, color);
}

// Function to draw a game object on a square
void drawObject(ALLEGRO_DISPLAY* display, int row, int col, const struct GameObject* object) {
    // Draw the image if available, otherwise draw a colored rectangle
    if (object->image != NULL) {
        al_draw_bitmap(object->image, col * SQUARE_SIZE, row * SQUARE_SIZE, 0);
    } else {
        ALLEGRO_COLOR color = al_map_rgb(255, 255 - object->health * 10, 255 - object->health * 10);
        drawSquare(display, row, col, color);
    }
}

int main() {
    ALLEGRO_DISPLAY* display = NULL;

    // Initialize Allegro
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }

    // Initialize Allegro image addon
    if (!al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize Allegro image addon!\n");
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

    // Create a 2D array of game objects
    struct GameObject gameGrid[GRID_SIZE][GRID_SIZE];

    // Load images for cat and dog
    ALLEGRO_BITMAP* catImage = al_load_bitmap("cat.png");
    ALLEGRO_BITMAP* dogImage = al_load_bitmap("dog.png");

    // Initialize game objects (for demonstration purposes)
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            gameGrid[row][col].health = rand() % 10; // Random health value (0 to 9)
            gameGrid[row][col].attack = rand() % 10; // Random attack value (0 to 9)

            // Assign images based on some conditions (you may modify this logic)
            if (gameGrid[row][col].health > 5) {
                gameGrid[row][col].image = catImage; // Assign cat image
            } else {
                gameGrid[row][col].image = dogImage; // Assign dog image
            }
        }
    }

    // Main game loop
    while (1) {
        al_clear_to_color(al_map_rgb(255, 255, 255)); // Clear the display

        // Draw the grid
        for (int row = 0; row < GRID_SIZE; ++row) {
            for (int col = 0; col < GRID_SIZE; ++col) {
                drawSquare(display, row, col, al_map_rgb(200, 200, 200)); // Draw a grid square
                drawObject(display, row, col, &gameGrid[row][col]); // Draw the object on the square
            }
        }

        // Flip the display
        al_flip_display();

        // Wait for a short duration to control the frame rate (you may adjust this)
        al_rest(0.1);
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_bitmap(catImage);
    al_destroy_bitmap(dogImage);

    return 0;
}
