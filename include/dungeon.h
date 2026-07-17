#pragma once

#include <raylib.h>
#include <vector>

#include "direction.h"

struct Wall {
  Vector3 pos = {};
  int rotation = 0;

  int width = 6;
  int length = 30;
  int height = 10;
};

struct Module {
  Vector3 pos;
  std::vector<Direction> wallDirs;
};
// TODO: make module init more intuitve/readable

struct Map {
  std::vector<Module> modules;
};

class Dungeon {
public:
  Dungeon();
  Map map;

  void createWall(Vector3 pos, int rotation = 90);
  void generateWalls();

  std::vector<Wall> walls;
  std::vector<Module> modules;

  Model wallModel;

  void generateMap();
  void convertGraph();
  void generateGraph();

private:
  static constexpr float ModuleSize = 30.0f;
  static constexpr float WallWidth = 5.0f;
  static constexpr float WallHeight = 10.0f;
  static constexpr float WallLength = ModuleSize;
};
