#include "square.h"

#include "trap.h"

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
    s->walls[0] = s->walls[1] = s->walls[2] = s->walls[3] = 0;
    s->character = NULL;
    s->is_trap = false;
    s->type = NOTHING;
    s->trap = NULL;
    return s;
}

void destroy_square(square_t *s)
{
    free(s);
}

void draw_square(square_t *s)
{
    al_draw_rectangle(s->x1, s->y1, s->x2, s->y2, al_map_rgb(s->r, s->g, s->b), 2);
    if (s->walls[0]) // LEFT
    {
        al_draw_line(s->x1, s->y1, s->x1, s->y2, al_map_rgb(147, 154, 70), 25);
    }
    if (s->walls[1]) // UP
    {
        al_draw_line(s->x1, s->y1, s->x2, s->y1, al_map_rgb(147, 154, 70), 25);
    }
}
void update_square(square_t *s, state_t _new_type, void *_new_character)
{
    s->type = _new_type;
    s->character = _new_character;
    switch (s->type)
    {
    case NOTHING:
        s->r = 160;
        s->g = 156;
        s->b = 101;
        break;

        // case TRAP:
        //     if (((trap_t *)s->character)->is_reveal)
        //     {
        //         s->r = 3;
        //         s->g = 0;
        //         s->b = 8;
        //     }
        //     else
        //     {
        //         s->r = 160;
        //         s->g = 156;
        //         s->b = 101;
        //     }
        //     break;

    case MOUSE:
        s->r = 240;
        s->g = 25;
        s->b = 20;
        break;

    case CAT:
        s->r = 18;
        s->g = 177;
        s->b = 233;
        break;

    case DOG:
        s->r = 111;
        s->g = 47;
        s->b = 166;
        break;

    case FISH:
        s->r = 45;
        s->g = 97;
        s->b = 41;
        break;

        // case BONUS:
        //     s->r = 244;
        //     s->g = 151;
        //     s->b = 20;
        //     break;

    default:
        fprintf(stderr, "update_square():Not valid state");
        break;
    }
}

bool set_square_as_trap(square_t *s)
{
    if (s->is_trap == true)
    {
        return false;
    }
    s->is_trap = true;
    return true;
}
