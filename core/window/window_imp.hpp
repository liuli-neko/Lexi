#pragma once

#include <Btk/comctl.hpp>
#include <Btk/context.hpp>

#include "common/utils.hpp"

namespace lexi {
namespace core {

class WindowImp : public Btk::Widget {
public:
  WindowImp();
  auto DrawRect(const Rectd &rect) const -> void;
  auto DrawString(StringView str, const Rectd &rect) const -> void;
  auto DrawImg(const Mat &img, const Rectd &rect) const -> void;
  auto DrawLine(const Pointd &x, const Pointd &y, const Color &color,
                const int thickness, const LineType &line_type) const -> void;
  auto SetPainterColor(const Color &color) -> void;
private:
};

} // namespace core
} // namespace lexi