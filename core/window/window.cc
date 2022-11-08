#include "window.hpp"
#include "Btk/widget.hpp"

namespace lexi {
namespace core {

class WindowImp {
public:
  WindowImp() {}
  auto DrawRect(const Rectd &rect) const -> void {}
  auto DrawString(StringView str) const -> void {}
  auto DrawImg(const Mat &img) const -> void {}
  auto DrawLine(const Pointd &x, const Pointd &y, const Color &color,
                const int thickness, const LineType &line_type) const -> void {}
  auto SetPainterColor(const Color &color) -> void {}

private:
};

Window::Window() { imp_ = new WindowImp(); }
Window::~Window() { delete imp_; }
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