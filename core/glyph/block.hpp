#pragma once

#include "glyph.hpp"

namespace lexi {
namespace core {
class Block : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Block);

 public:
  auto Draw(Window *win) -> void override;
};
}  // namespace core
}  // namespace lexi