#pragma once

#include "Btk/defs.hpp"
#include "glyph.hpp"

namespace lexi {
namespace core {

class Character : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Character);

 public:
  auto SetValue(uchar_t ch) -> void;
  auto Draw(Window *win) -> void override;
  auto ToCharacter() -> String override;
  virtual ~Character() override;

 protected:
  Character(uchar_t ch = '\0');

 protected:
  uchar_t character_;
};

}  // namespace core
}  // namespace lexi