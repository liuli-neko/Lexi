#pragma once

#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <Btk/widget.hpp>

namespace lexi {
namespace core {

using Pointd = Btk::PointImpl<double>;
using StringView = Btk::u8string_view;
using Mat = Btk::PixBuffer;
using Color = Btk::Color;
using Rectd = Btk::RectImpl<double>;

class WindowImp;

enum LineType { SOLID_LINE = 0, DOTTED_LINE = 1, TYPE_SIZE = 2 };

class Window {
public:
  Window();
  ~Window();
  auto DrawRect(const Rectd &rect) const -> void;
  auto DrawString(StringView str) const -> void;
  auto DrawImg(const Mat &img) const -> void;
  auto DrawLine(const Pointd &x, const Pointd &y, const Color &color,
                const int thickness = 1,
                const LineType &line_type = SOLID_LINE) const -> void;
  auto SetPainterColor(const Color &color) -> void;

private:
  WindowImp *imp_;
};

} // namespace core
} // namespace lexi
