#include "ui.h"
#include "raylib.h"

UI::UI() {}
void UI::printCoords(Vector3 pos) {
  DrawText(TextFormat("x: %i y: %i z: %i", (int)pos.x, (int)pos.y, (int)pos.z),
           GetScreenWidth() - 225, 10, 20, WHITE);
}
