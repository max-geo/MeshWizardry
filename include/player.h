#pragma once

#include "hud_prop.h"
#include "input.h"
#include "raylib.h"
#include <vector>

class Player {
public:
  Camera3D camera;
  Player(Camera3D camera);
  void move(InputState input);
  void updateCamera();
  Vector3 pos;
  std::vector<HUDProp> HUDProps;
};
