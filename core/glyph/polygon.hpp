#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {

class Polygon : public Glyph {
public:
  [[noreturn]] auto Draw(Window *win) -> void override;
  [[nodiscard]] auto Intersects(const Pointd &pt) -> bool override;
};

} // namespace core
} // namespace lexi