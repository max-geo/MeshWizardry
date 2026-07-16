#include "dungeon.h"
#include "raylib.h"

Dungeon::Dungeon() {
  // load models
  Mesh wallMesh = GenMeshCube(WallLength, WallHeight, WallWidth);
  wallModel = LoadModelFromMesh(wallMesh);
}

void Dungeon::generateMap() {
  modules.push_back(Module{{10, 0, 40}, true, true, false, false});
  modules.push_back(Module{{10, 0, 70}, true, true, false, false});
  modules.push_back(Module{{10, 0, 100}, true, true, false, false});
  modules.push_back(Module{{40, 0, 130}, false, false, true, true});
  modules.push_back(Module{{-20, 0, 130}, false, false, true, true});
}

void Dungeon::createWall(Vector3 pos, int rotation) {

  Wall wall{{pos.x, pos.y, pos.z}, rotation};

  // wall.rotate = true;
  walls.push_back(wall);
}

void Dungeon::generateWalls() {
  float w = WallWidth;
  float l = WallLength;

  for (const Module &m : modules) {
    if (m.west) {
      createWall({m.pos.x, m.pos.y, m.pos.z});
    }

    if (m.east) {
      createWall({m.pos.x + w - l, m.pos.y, m.pos.z});
    }

    if (m.north) {
      createWall({m.pos.x - l / 2 + w / 2, m.pos.y, m.pos.z + l / 2 - w / 2},
                 0);
    }

    if (m.south) {
      createWall({m.pos.x + w / 2 - l / 2, m.pos.y, m.pos.z + w / 2 - l / 2},
                 0);
    }
  }
}
