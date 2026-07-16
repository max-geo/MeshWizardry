#pragma once

#include <raylib.h>

enum Direction { North, East, South, West };

extern Vector3 DirectionVectors[4];

Direction rotateRight(Direction d);
