#include "dungeon.h"
#include "raylib.h"

Dungeon::Dungeon() {
  this->map = generateMap();

  // load models
  Mesh wallMesh = GenMeshCube(WallLength, WallHeight, WallWidth);
  wallModel = LoadModelFromMesh(wallMesh);
}

Map Dungeon::generateMap() {
  Map map;
  return map;
}

void Dungeon::createWall(Vector3 pos, int rotation) {

  Wall wall{{pos.x, pos.y, pos.z}, rotation};

  // wall.rotate = true;
  walls.push_back(wall);
}

void Dungeon::generateWalls() {
  for (const Module &m : modules) {
    if (m.west) {
      createWall(m.pos);
    }

    if (m.east) {
      createWall({m.pos.x - WallLength, m.pos.y, m.pos.z});
    }

    if (m.north) {
      createWall({m.pos.x - WallLength / 2, m.pos.y, m.pos.z + WallLength / 2},
                 0);
    }

    if (m.south) {
      createWall({m.pos.x - WallLength / 2, m.pos.y, m.pos.z - WallLength / 2},
                 0);
    }
  }
}
