#pragma once

struct InputState {
  bool forward = false;
  bool backward = false;
  bool left = false;
  bool right = false;
  bool up = false;
  bool down = false;
};

class InputHandler {
public:
  InputState handleInput();
};
