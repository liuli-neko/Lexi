#include "layout_horizontal.hpp"
#include "core/window/layout/layout_node.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutHorizontal::LayoutHorizontal(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode_ = HORIZONTAL_ZOOM;
}

auto LayoutHorizontal::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  if (scaling > 1) {
    return std::make_pair(minize_size_.first * scaling, minize_size_.second);
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi