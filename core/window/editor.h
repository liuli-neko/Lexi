#pragma once

#include "core/glyph/glyph.hpp"
#include "window.hpp"

namespace lexi {
namespace core {

class RTFBox final : public Window {
  private:
  RTFBox rtf_box;
  Glyph *root;
};

class Editor {
 public:
  auto Show() -> void;
  auto rePaint() -> void;
};

}  // namespace core
}  // namespace lexi
