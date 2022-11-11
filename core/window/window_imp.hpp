#pragma once

#include <Btk/comctl.hpp>
#include <Btk/context.hpp>

#include "common/utils.hpp"

namespace lexi {
namespace core {

class WindowImp : public Btk::Widget {
public:
  WindowImp();
  ~WindowImp();
  auto DrawRect(const Rectd &rect) const -> void;
  auto DrawString(StringView str, const Rectd &rect) const -> void;
  auto DrawImg(const Mat &img, const Rectd &rect) const -> void;
  auto DrawLine(const Pointd &x, const Pointd &y) const -> void;
  auto SetPainterColor(const Color &color) -> void;
  auto GetPainter() -> Painter *;
  auto GetPen() -> Pen *;

private:
  Painter *painter_;
  Pen *pen_;
};

} // namespace core
} // namespace lexi