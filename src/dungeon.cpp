#include "dungeon.h";
#include "raylib.h"

Dungeon::Dungeon() { this->map = generateMap(); }
Map Dungeon::generateMap() {
  Map map;
  return map;
}

Wall Dungeon::createWall() {
  Mesh wallMesh = GenMeshCube(30, 10, 5);
  Model wallModel = LoadModelFromMesh(wallMesh);

  Wall Wall{10, 0, 10};
  return Wall;
}
