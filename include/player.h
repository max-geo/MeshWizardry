#pragma once

#include "input.h"
#include "raylib.h"

class Player {
public:
  Camera3D camera;
  Player(Camera3D camera);
  void move(InputState input);
  void updateCamera();
  Vector3 position;
};
