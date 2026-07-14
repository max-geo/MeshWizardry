#include <raylib.h>

#include "dungeon.h"
#include "input.h"
#include "player.h"
#include "ui.h"

#include <iostream>

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

  dungeon.modules.push_back(Module{{10, 0, 40}, true, true, true, true});

  dungeon.generateWalls();

  while (!WindowShouldClose()) {
    InputState input = inputHandler.handleInput();

    player.move(input);
    player.updateCamera();

    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(player.camera);

    for (Wall w : dungeon.walls) {
      DrawModelWiresEx(dungeon.wallModel, w.position, {0, 1, 0}, w.rotation,
                       {1, 1, 1}, WHITE);
    }

    EndMode3D();

    ui.printCoords(player.position);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
