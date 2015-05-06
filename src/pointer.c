// vim:ts=4:sw=4:expandtab
#include "all.h"

Direction pointer_touches_border(Position pointer) {
    Output *current;
    TAILQ_FOREACH(current, &outputs, outputs) {
        Rect rect = current->rect;

        // TODO this isn't pixel perfect yet.
        if (pointer.y == rect.y && pointer.x >= rect.x && pointer.x <= rect.x + rect.width)
            return D_TOP;
        if (pointer.x == rect.x && pointer.y >= rect.y && pointer.y <= rect.y + rect.height)
            return D_LEFT;
        if (pointer.y == rect.y + rect.height && pointer.x >= rect.x && pointer.x <= rect.x + rect.width)
            return D_BOTTOM;
        if (pointer.x == rect.x + rect.width && pointer.y >= rect.y && pointer.y <= rect.y + rect.height)
            return D_RIGHT;
    }

    return D_NONE;
}

void pointer_warp_to_adjacent_output(Position pointer, Direction direction) {
    // TODO implement this
}
