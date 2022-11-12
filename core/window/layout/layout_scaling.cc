#include "layout_scaling.hpp"
#include "core/window/layout/layout_node.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutScaling::LayoutScaling(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode_ = SCALING_ZOOM;
}
auto LayoutScaling::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  if (scaling > 1) {
    return std::make_pair(minize_size_.first * scaling,
                          minize_size_.second * scaling);
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi