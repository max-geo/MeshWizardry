#include "render.h"

void Renderer::renderDungeon(Dungeon &d) {
  for (Wall &w : d.walls) {
    DrawModelWiresEx(d.wallModel, w.pos, {0, 1, 0}, w.rotation, {1, 1, 1},
                     WHITE);
  }
}

void Renderer::renderHUDProps(Player &p, int frame) {

  for (HUDProp &h : p.HUDProps) {
    Vector3 forward = DirectionVectors[p.facing];
    Vector3 right = DirectionVectors[rotateRight(p.facing)];

    Vector3 pos = p.pos;
    pos = Vector3Add(pos, Vector3Scale(right, h.offset.x));
    pos = Vector3Add(pos, {0.0f, h.offset.y, 0.0f});
    pos = Vector3Add(pos, Vector3Scale(forward, h.offset.z));

    UpdateModelAnimation(h.model, h.animations[0], frame);
    DrawModelWiresEx(h.model, pos, {0, 1, 0}, p.facing * 90, h.scale, WHITE);
  }
}
