#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {

class Character : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Character);

public:
  [[noreturn]] auto Draw(Window *win) -> void override;
  [[nodiscard]] auto Intersects(const Pointd &pt) -> bool override;
};

} // namespace core
} // namespace lexi