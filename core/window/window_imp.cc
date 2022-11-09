#include "window_imp.hpp"
#include "Btk/painter.hpp"

namespace lexi {
namespace core {

WindowImp::WindowImp() : Btk::Widget() {}

auto WindowImp::DrawRect(const Rectd &rect) const -> void {
  Btk::Painter &pt = painter();
  pt.draw_rect(rect);
}
auto WindowImp::DrawString(StringView str, const Rectd &rect) const -> void {
  Btk::Painter &pt = painter();
  pt.push_scissor(rect);
  pt.draw_text(str, rect.x, rect.y);
  pt.pop_scissor();
}
auto WindowImp::DrawImg(const Mat &img, const Rectd &rect) const -> void {
  Btk::Painter &pt = painter();
  Btk::Brush brush(img);
  pt.set_brush(brush);
  pt.fill_rect(rect);
}
auto WindowImp::DrawLine(const Pointd &pt_s, const Pointd &pt_e,
                         const Color &color, const int thickness,
                         const LineType &line_type) const -> void {
  Btk::Painter &pt = painter();
  // TODO(BusyStudent):add pt.get_color();
  // const Color& color_bak = pt.get_color();
  pt.set_color(color);
  pt.set_stroke_width(thickness);
  Btk::Pen pen;
  pen.set_dash_style(line_type);
  pt.set_pen(pen);
  pt.draw_line(pt_s.x, pt_s.y, pt_e.x, pt_e.y);
  pt.set_pen(nullptr);
  // pt.set_color(color_bak);
}
auto WindowImp::SetPainterColor(const Color &color) -> void {
  Btk::Painter &pt = painter();
  pt.set_color(color);
}

} // namespace core
} // namespace lexi