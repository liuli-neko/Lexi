#pragma once

#include "Btk/defs.hpp"
#include "glyph.hpp"

namespace lexi {
namespace core {

class Character : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Character);

public:
  auto Draw(Window *win) -> void override;
protected:
  uchar_t character_;
};

} // namespace core
} // namespace lexi