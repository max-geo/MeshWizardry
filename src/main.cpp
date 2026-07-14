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

  Mesh cubeMesh = GenMeshCube(100, 100, 100);
  Model cubeModel = LoadModelFromMesh(cubeMesh);

  Vector3 camera_pos = {0, 5, -15};
  Vector3 camera_lookAt = {1, 0, 0};
  Vector3 camera_lookUp = {0, 1, 0};

  Camera3D camera = {camera_pos, camera_lookAt, camera_lookUp, 90,
                     CAMERA_PERSPECTIVE};

  InputHandler inputHandler;
  Player player = Player(camera);
  Dungeon dungeon = Dungeon();

  Wall wall = dungeon.createWall();

  while (!WindowShouldClose()) {
    InputState input = inputHandler.handleInput();

    player.move(input);
    player.updateCamera();

    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(player.camera);

    DrawModelWires(cubeModel, {20, -5, 0}, 1, WHITE);
    DrawGrid(10, 1.0f);
    // DrawModelWires(wall.model, wall.position, 1, WHITE);

    EndMode3D();

    ui.printCoords(player.position);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
