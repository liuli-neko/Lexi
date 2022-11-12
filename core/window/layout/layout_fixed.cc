#include "layout_fixed.hpp"
#include "core/window/layout/layout_node.hpp"
#include <utility>

namespace lexi {
namespace core {

LayoutFixed::LayoutFixed(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode_ = FIXED_SIZE;
}
auto LayoutFixed::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  return minize_size_;
}

} // namespace core
} // namespace lexi