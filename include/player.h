#pragma once

#include <vector>

#include "direction.h"
#include "hud_prop.h"
#include "input.h"
#include "raylib.h"

class Player {
public:
  Camera3D camera;
  Player();
  void move(InputState input, bool sideDirectCameraTurn = false);
  void updateCamera();
  Vector3 pos;
  std::vector<HUDProp> HUDProps;
  Direction facing = Direction::North;

private:
  void moveForward();
  void moveBackward();
};
