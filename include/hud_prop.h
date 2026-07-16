#pragma once

#include <raylib.h>

struct HUDProp {
  Model model;
  Vector3 offset;
  int rotationSpeed;
  int angle;
  float scale;
  ModelAnimation *animations;
  int animCount = 0;
};
