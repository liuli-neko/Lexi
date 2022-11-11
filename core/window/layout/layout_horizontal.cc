#include "layout_horizontal.hpp"
#include "core/window/layout/layout_node.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutHorizontal::LayoutHorizontal(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode = HORIZONTAL_ZOOM;
}

auto LayoutHorizontal::GetDefaultSize() -> std::pair<double, double> {
  if (fabs(rect_.x + 1) > 1e-8 && fabs(rect_.y + 1) > 1e-8) {
    if (rect_.w > minize_size_.first) {
      return std::make_pair(rect_.w, minize_size_.second);
    }
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi