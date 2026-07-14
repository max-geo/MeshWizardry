#pragma once
#include <raylib.h>
#include <vector>

struct Wall {
  Vector3 position = {};
  int rotation = 0;

  int width = 5;
  int length = 30;
  int height = 10;
};

struct Module {
  Vector3 pos;
  bool east;
  bool west;
  bool north;
  bool south;
};

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

  Map generateMap();

private:
  static constexpr float ModuleSize = 30.0f;
  static constexpr float WallWidth = 5.0f;
  static constexpr float WallHeight = 10.0f;
  static constexpr float WallLength = ModuleSize;
};
