#include "rectangle.hpp"

namespace lexi {
namespace core {
auto Rectangle::Draw(Window *win) -> void { win->DrawRect(rect_); };
}  // namespace core
}  // namespace lexi