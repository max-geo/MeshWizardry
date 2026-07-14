#include <raylib.h>
#include <vector>

using namespace std;

struct Wall {
  Vector3 position = {};
  Model model;
};

struct module {
  Wall east;
  Wall west;
  Wall north;
  Wall south;
};

struct Map {
  vector<module> modules;
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
