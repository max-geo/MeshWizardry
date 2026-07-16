#pragma once

#include <raylib.h>

struct HUDProp {
  Model model;
  Vector3 offset;
  int rotationSpeed;
  int angle;
  Vector3 scale;
  ModelAnimation *animations;
  int animCount = 0;
};
