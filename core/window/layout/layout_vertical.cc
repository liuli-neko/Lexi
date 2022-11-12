#include "core/window/layout/layout_vertical.hpp"
#include "core/window/layout/layout_node.hpp"
#include "layout_vertical.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutVertical::LayoutVertical(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode_ = VERTICAL_ZOOM;
}
auto LayoutVertical::GetScalingSize(const double scaling)
    -> std::pair<double, double> {

  if (scaling > 1) {
    return std::make_pair(minize_size_.first, minize_size_.second * scaling);
  }
  return minize_size_;
}

} // namespace core
} // namespace lexi