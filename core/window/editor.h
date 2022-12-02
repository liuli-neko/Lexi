#pragma once

#include "core/glyph/glyph.hpp"
#include "window.hpp"

namespace lexi {
namespace core {

class RTFBox final : public Window {};

class Editor {
public:
  auto Show() -> void;
  auto rePaint() -> void;

private:
  RTFBox rtf_box;
  Glyph *root;
};

} // namespace core
} // namespace lexi
