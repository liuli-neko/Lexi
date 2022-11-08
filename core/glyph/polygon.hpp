#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {

class Polygon : public Glyph {
 public:
  void Draw(Window* win) override;
  bool Intersects(const Pointd& pt) override;
};

}  // namespace core
}  // namespace lexi