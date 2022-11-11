#include "layout_scaling.hpp"
#include "core/window/layout/layout_node.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutScaling::LayoutScaling(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode = SCALING_ZOOM;
}
auto LayoutScaling::GetDefaultSize() -> std::pair<double, double> {
  if (fabs(rect_.x + 1) > 1e-8 && fabs(rect_.y + 1) > 1e-8) {
    double scaling =
        std::min(rect_.w / minize_size_.first, rect_.h / minize_size_.second);
    if (scaling > 1) {
      return std::make_pair(minize_size_.first * scaling,
                            minize_size_.second * scaling);
    }
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi