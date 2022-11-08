#include "window.hpp"
#include "window_imp.hpp"

namespace lexi {
namespace core {

Window::Window() {
  ctxt = static_cast<void *>(new Btk::UIContext);
  imp_ = new WindowImp();
}
Window::~Window() {
  delete imp_;
  delete static_cast<Btk::UIContext *>(ctxt);
}
auto Window::DrawRect(const Rectd &rect) const -> void { imp_->DrawRect(rect); }
auto Window::DrawString(StringView str) const -> void { imp_->DrawString(str); }
auto Window::DrawImg(const Mat &img) const -> void { imp_->DrawImg(img); }
auto Window::DrawLine(const Pointd &x, const Pointd &y, const Color &color,
                      const int thickness, const LineType &line_type) const
    -> void {
  imp_->DrawLine(x, y, color, thickness, line_type);
}
auto Window::SetPainterColor(const Color &color) -> void {
  imp_->SetPainterColor(color);
}

} // namespace core
} // namespace lexi