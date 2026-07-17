#include "dungeon.h"
#include "raylib.h"

Dungeon::Dungeon() {
  // load models
  Mesh wallMesh = GenMeshCube(WallLength, WallHeight, WallWidth);
  wallModel = LoadModelFromMesh(wallMesh);
}

void Dungeon::generateMap() {
  modules.push_back(Module{{10, 0, 40}, {Direction::East, Direction::West}});
  modules.push_back(Module{{10, 0, 70}, {Direction::West, Direction::East}});
  modules.push_back(Module{{10, 0, 100}, {Direction::West, Direction::East}});
  modules.push_back(Module{{40, 0, 130}, {Direction::South, Direction::North}});
  modules.push_back(
      Module{{-20, 0, 130}, {Direction::South, Direction::North}});
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
    for (auto &d : m.wallDirs) {
      switch (d) {
      case (Direction::West):

        createWall({m.pos.x, m.pos.y, m.pos.z});
        break;
      case Direction::East:
        createWall({m.pos.x + w - l, m.pos.y, m.pos.z});
        break;

      case Direction::North:
        createWall({m.pos.x - l / 2 + w / 2, m.pos.y, m.pos.z + l / 2 - w / 2},
                   0);
        break;

      case Direction::South:
        createWall({m.pos.x + w / 2 - l / 2, m.pos.y, m.pos.z + w / 2 - l / 2},
                   0);
        break;
      }
    }
  }
}
