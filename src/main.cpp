#include <raylib.h>
#include <raymath.h>

#include "direction.h"
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
  Player player = Player();
  Dungeon dungeon = Dungeon();

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

    for (Wall &w : dungeon.walls) {
      DrawModelWiresEx(dungeon.wallModel, w.pos, {0, 1, 0}, w.rotation,
                       {1, 1, 1}, WHITE);
    }

    for (HUDProp &h : player.HUDProps) {
      Vector3 forward = DirectionVectors[player.facing];
      Vector3 right = DirectionVectors[rotateRight(player.facing)];

      Vector3 pos = player.pos;
      pos = Vector3Add(pos, Vector3Scale(right, h.offset.x));
      pos = Vector3Add(pos, {0.0f, h.offset.y, 0.0f});
      pos = Vector3Add(pos, Vector3Scale(forward, h.offset.z));

      UpdateModelAnimation(h.model, h.animations[0], frame);
      DrawModelWiresEx(h.model, pos, {0, 1, 0}, player.facing * 90, h.scale,
                       WHITE);
    }

    EndMode3D();

    ui.printCoords(player.pos);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
