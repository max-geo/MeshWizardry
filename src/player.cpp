#include "raylib.h"
#include "raymath.h"

#include "direction.h"
#include "hud_prop.h"
#include "input.h"
#include "player.h"

Player::Player() {
  pos = {-2.5, 5, 10};

  camera = {{}, {}, {0, 1, 0}, 90, CAMERA_PERSPECTIVE};
  updateCamera();

  HUDProp cube;

  // init handheld hudprop items
  cube.model = LoadModel("../assets/tesseract.glb");
  cube.offset = {0.7, -0.4f, 0.8f};
  cube.animations =
      LoadModelAnimations("../assets/tesseract.glb", &cube.animCount);
  cube.scale = {0.1, 0.1, 0.1};
  HUDProps.push_back(cube);
}

void Player::moveForward() {
  pos = Vector3Add(pos, Vector3Scale(DirectionVectors[facing], 30));
}
void Player::moveBackward() {
  pos = Vector3Subtract(pos, Vector3Scale(DirectionVectors[facing], 30));
}

// sideDirectCameraTurn = False --> first press d, that turns camera, then w to
// move forward; else, pressing d turns the camera and also walks forward
// FIX: not used rn, need collision first
void Player::move(InputState input, bool sideDirectCameraTurn) {
  if (input.forward)
    moveForward();
  if (input.backward)
    moveBackward();

  if (input.left) {
    facing = Direction(((facing) + 3) % 4);
    // if (sideDirectCameraTurn)
    //   moveForward();
  }

  if (input.right) {
    facing = Direction(((facing) + 1) % 4);
    // if (sideDirectCameraTurn)
    //   moveForward();
  }
  if (input.up)
    pos.y += 1;
  if (input.down)
    pos.y -= 1;
}

void Player::updateCamera() {
  camera.position = pos;
  camera.target = Vector3Add(pos, Vector3Scale(DirectionVectors[facing], 1000));
}
