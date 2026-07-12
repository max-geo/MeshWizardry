#include "player.h"
#include "input.h"

#include <iostream>

Player::Player(Camera3D camera) {
  position = camera.position;
  this->camera = camera;
}
void Player::move(InputState input) {
  if (input.forward)
    position.x += 1;
  if (input.backward)
    position.x -= 1;
  if (input.left)
    position.z -= 1;
  if (input.right)
    position.z += 1;
  if (input.up)
    position.y += 1;
  if (input.down)
    position.y -= 1;
}
void Player::updateCamera() { camera.position = position; }
