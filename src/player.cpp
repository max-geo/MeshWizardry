#include "player.h"
#include "hud_prop.h"
#include "input.h"

Player::Player(Camera3D camera) {
  pos = camera.position;
  this->camera = camera;

  HUDProp cube;

  // init handheld hudprop items
  cube.model = LoadModel("../assets/tesseract.glb");
  cube.offset = {-0.7, -0.4f, 0.8f};
  cube.animations =
      LoadModelAnimations("../assets/tesseract.glb", &cube.animCount);
  cube.scale = 0.1;
  HUDProps.push_back(cube);
}

void Player::move(InputState input) {
  if (input.forward)
    pos.z += 15;
  if (input.backward)
    pos.z -= 15;
  if (input.left)
    pos.x += 1;
  if (input.right)
    pos.x -= 1;
  if (input.up)
    pos.y += 1;
  if (input.down)
    pos.y -= 1;
}

void Player::updateCamera() { camera.position = pos; }
