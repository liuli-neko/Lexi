#pragma once

#include "glyph.h"

namespace lexi {
namespace core {

class Polygon : public Glyph {
 public:
  void Draw(Window* win) override;
  bool Intersects(const Point& pt) override;
};

}  // namespace core
}  // namespace lexi