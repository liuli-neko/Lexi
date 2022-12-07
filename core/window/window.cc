#include "window.hpp"

namespace lexi {
namespace core {

Window::Window() {
  show();
  painter_ = &painter();
  pen_ = new Pen;
}

auto Window::DrawRect(const Rectd &rect) const -> void {
  painter_->draw_rect(rect);
}
auto Window::DrawString(StringView str, const Rectd &rect,
                        const double offset_x, const double offset_y) const
    -> void {
  painter_->push_scissor(rect);
  painter_->draw_text(str, rect.x + offset_x, rect.y + offset_y);
  painter_->pop_scissor();
}

auto Window::DrawImg(const Mat &img, const Rectd &rect) const -> void {
  Btk::Brush brush(img);
  painter_->set_brush(brush);
  painter_->fill_rect(rect);
}

auto Window::DrawLine(const Pointd &pt_s, const Pointd &pt_e) const -> void {
  painter_->set_pen(pen_);
  painter_->draw_line(pt_s.x, pt_s.y, pt_e.x, pt_e.y);
  painter_->set_pen(nullptr);
}

auto Window::SetPainterColor(const Color &color) -> void {
  painter_->set_color(color);
}

Window::~Window() { delete pen_; }

auto Window::SetBound(const double x, const double y, const double w,
                      const double h) -> void {
  set_rect(x, y, w, h);
}

auto Window::SetBound(const Rectd &rect) -> void {
  set_rect(rect.x, rect.y, rect.w, rect.h);
}

}  // namespace core
}  // namespace lexi