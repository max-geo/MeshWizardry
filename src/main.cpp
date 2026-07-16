#include <raylib.h>

#include "dungeon.h"
#include "input.h"
#include "player.h"
#include "ui.h"

int main(void) {
  UI ui;

  const int screenWidth = 1800;
  const int screenHeight = 1000;

  InitWindow(screenWidth, screenHeight, "testingtester");

  SetTargetFPS(60);

  Vector3 camera_pos = {0, 5, -15};
  Vector3 camera_lookAt = {0, 5, 100};
  Vector3 camera_lookUp = {0, 1, 0};

  Camera3D camera = {camera_pos, camera_lookAt, camera_lookUp, 90,
                     CAMERA_PERSPECTIVE};

  InputHandler inputHandler;
  Player player = Player(camera);
  Dungeon dungeon = Dungeon();

  dungeon.generateMap();
  dungeon.generateWalls();

  int frame = 0;
  while (!WindowShouldClose()) {

    frame++;

    InputState input = inputHandler.handleInput();

    player.move(input);
    player.updateCamera();

    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(player.camera);

    for (Wall &w : dungeon.walls) {
      DrawModelWiresEx(dungeon.wallModel, w.pos, {0, 1, 0}, w.rotation,
                       {1, 1, 1}, WHITE);
    }

    for (HUDProp &h : player.HUDProps) {
      UpdateModelAnimation(h.model, h.animations[0], frame);
      DrawModelWires(h.model,
                     {
                         player.pos.x + h.offset.x,
                         player.pos.y + h.offset.y,
                         player.pos.z + h.offset.z,
                     },
                     h.scale, WHITE);
    }

    EndMode3D();

    ui.printCoords(player.pos);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
