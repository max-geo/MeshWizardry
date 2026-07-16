#include "direction.h"

Vector3 DirectionVectors[4] = {
    {0, 0, 1},  // North
    {-1, 0, 0}, // East
    {0, 0, -1}, // South
    {1, 0, 0},  // West
};

Direction rotateRight(Direction d) { return Direction((d + 1) % 4); }
