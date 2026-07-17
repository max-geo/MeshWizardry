#pragma once

#include <raylib.h>
#include <raymath.h>

#include "dungeon.h"
#include "player.h"

class Renderer {
public:
  void renderDungeon(Dungeon &d);
  void renderHUDProps(Player &p, int frame);
  void drawUI();
};
