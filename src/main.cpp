#include <raylib.h>
#include <raymath.h>

#include "direction.h"
#include "dungeon.h"
#include "input.h"
#include "player.h"
#include "render.h"
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
  Player player = Player();
  Dungeon dungeon = Dungeon();
  Renderer renderer;

  dungeon.generateMap();
  dungeon.generateWalls();

  int frame = 0;
  while (!WindowShouldClose()) {

    frame++;

    InputState input = inputHandler.handleInput();

    player.move(input, true);
    player.updateCamera();

    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(player.camera);

    renderer.renderDungeon(dungeon);
    renderer.renderHUDProps(player, frame);

    EndMode3D();

    ui.printCoords(player.pos);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
