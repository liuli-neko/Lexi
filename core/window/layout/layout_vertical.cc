#include "core/window/layout/layout_vertical.hpp"
#include "core/window/layout/layout_node.hpp"
#include "layout_vertical.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutVertical::LayoutVertical(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode = VERTICAL_ZOOM;
}
auto LayoutVertical::GetDefaultSize() -> std::pair<double, double> {
  if (fabs(rect_.x + 1) > 1e-8 && fabs(rect_.y + 1) > 1e-8) {
    if (rect_.h > minize_size_.second) {
      return std::make_pair(minize_size_.first, rect_.h);
    }
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi