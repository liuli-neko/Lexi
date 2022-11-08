#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {

class Rectangle : public Glyph {
 public:
  void Draw(Window* win) override;
  bool Intersects(const Pointd& pt) override;
};

}  // namespace core
}  // namespace lexi