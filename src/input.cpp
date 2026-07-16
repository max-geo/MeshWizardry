#include <raylib.h>

#include "direction.h"
#include "input.h"

InputState InputHandler::handleInput() {
  InputState input;

  input.forward = IsKeyPressed(KEY_W);
  input.backward = IsKeyPressed(KEY_S);
  input.left = IsKeyPressed(KEY_A);
  input.right = IsKeyPressed(KEY_D);
  input.up = IsKeyPressed(KEY_SPACE);
  input.down = IsKeyPressed(KEY_LEFT_SHIFT);

  return input;
};
