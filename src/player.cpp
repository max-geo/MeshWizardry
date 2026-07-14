#include "player.h"
#include "input.h"

#include <iostream>

Player::Player(Camera3D camera) {
  position = camera.position;
  this->camera = camera;
}

void Player::move(InputState input) {
  if (input.forward)
    position.z += 1;
  if (input.backward)
    position.z -= 1;
  if (input.left)
    position.x += 1;
  if (input.right)
    position.x -= 1;
  if (input.up)
    position.y += 1;
  if (input.down)
    position.y -= 1;
}

void Player::updateCamera() { camera.position = position; }
