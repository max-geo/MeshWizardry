#include "input.h"

#include <raylib.h>

InputState InputHandler::handleInput() {
  InputState input;

  input.forward = IsKeyDown(KEY_W);
  input.backward = IsKeyDown(KEY_S);
  input.left = IsKeyDown(KEY_A);
  input.right = IsKeyDown(KEY_D);
  input.up = IsKeyDown(KEY_SPACE);
  input.down = IsKeyDown(KEY_LEFT_SHIFT);

  return input;
};
