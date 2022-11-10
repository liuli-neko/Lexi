#include "window_imp.hpp"
#include "Btk/painter.hpp"
#include "common/utils.hpp"

namespace lexi {
namespace core {

WindowImp::WindowImp() : Btk::Widget() { painter_ = &painter(); }

auto WindowImp::DrawRect(const Rectd &rect) const -> void {
  painter_->draw_rect(rect);
}
auto WindowImp::DrawString(StringView str, const Rectd &rect) const -> void {
  painter_->push_scissor(rect);
  painter_->draw_text(str, rect.x, rect.y);
  painter_->pop_scissor();
}
auto WindowImp::DrawImg(const Mat &img, const Rectd &rect) const -> void {
  Btk::Brush brush(img);
  painter_->set_brush(brush);
  painter_->fill_rect(rect);
}
auto WindowImp::DrawLine(const Pointd &pt_s, const Pointd &pt_e,
                         const Color &color, const int thickness,
                         const LineType &line_type) const -> void {
  const Color& color_bak = painter_->color();
  painter_->set_color(color);
  painter_->set_stroke_width(thickness);
  Btk::Pen pen;
  pen.set_dash_style(line_type);
  painter_->set_pen(pen);
  painter_->draw_line(pt_s.x, pt_s.y, pt_e.x, pt_e.y);
  painter_->set_pen(nullptr);
  painter_->set_color(color_bak);
}
auto WindowImp::SetPainterColor(const Color &color) -> void {
  painter_->set_color(color);
}

} // namespace core
} // namespace lexi