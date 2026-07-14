#pragma once
#include <raylib.h>
#include <vector>

struct Wall {
  Vector3 position = {};
};

struct module {
  Vector3 position;
  bool east;
  bool west;
  bool north;
  bool south;
};

struct Map {
  std::vector<module> modules;
};

class Dungeon {
public:
  Dungeon();
  Map map;
  Wall createWall();

private:
  Map generateMap();

  vector<Wall> walls;
};
