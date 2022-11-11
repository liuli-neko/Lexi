#pragma once

#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <Btk/widget.hpp>
#include <bits/getopt_core.h>

#include "common/utils.hpp"

namespace lexi {
namespace core {

class WindowImp;

class Window {
public:
  Window();
  ~Window();
  auto DrawRect(const Rectd &rect) const -> void;
  auto DrawString(StringView str, const Rectd &rect) const -> void;
  auto DrawImg(const Mat &img, const Rectd &rect) const -> void;
  auto DrawLine(const Pointd &x, const Pointd &y) const -> void;
  auto SetPainterColor(const Color &color) -> void;

private:
  WindowImp *imp_;
  void *ctxt;
};

} // namespace core
} // namespace lexi
