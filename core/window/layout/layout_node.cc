#include "layout_node.hpp"
#include "common/utils.hpp"

namespace lexi {
namespace core {

LayoutNode::LayoutNode(Window *widget) : widget_(widget) {
  rect_ = Rectd(-1, -1, -1, -1);
  minize_size_ = {-1, -1};
  layout_mode_ = FREE_ZOOM;
}

auto LayoutNode::GetScalingSize(const double scaling)
    -> std::pair<double, double> {

  if (scaling > 1) {
    return std::make_pair(minize_size_.first * scaling,
                          minize_size_.second * scaling);
  }
  return minize_size_;
}

auto LayoutNode::SetMinimizeSize(const std::pair<double, double> &size)
    -> void {
  minize_size_ = size;
}

auto LayoutNode::SetAllowRect(const Rectd &rect) -> void { rect_ = rect; }

} // namespace core
} // namespace lexi