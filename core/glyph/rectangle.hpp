#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {

class Rectangle : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Rectangle);

public:
  auto Draw(Window *win) -> void override;
  bool Intersects(const Pointd &pt) override;
};

} // namespace core
} // namespace lexi