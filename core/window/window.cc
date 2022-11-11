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
auto Window::DrawString(StringView str, const Rectd &rect) const -> void {
  imp_->DrawString(str, rect);
}

auto Window::DrawImg(const Mat &img, const Rectd &rect) const -> void {
  imp_->DrawImg(img, rect);
}

auto Window::DrawLine(const Pointd &x, const Pointd &y) const -> void {
  imp_->DrawLine(x, y);
}

auto Window::SetPainterColor(const Color &color) -> void {
  imp_->SetPainterColor(color);
}

} // namespace core
} // namespace lexi