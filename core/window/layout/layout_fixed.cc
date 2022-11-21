#include "layout_fixed.hpp"
#include "common/log/lexi_log.hpp"
#include "core/window/layout/layout_node.hpp"

namespace lexi {
namespace core {

LayoutFixed::LayoutFixed(Window *wigdet) : LayoutNode(wigdet) {
  layout_mode_ = FIXED_SIZE;
}
auto LayoutFixed::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  return minize_size_;
}

auto LayoutFixed::SetAllowRect(const Rectd &rect, const double scaling)
    -> void {
  if (widget_ != nullptr && scaling >= 1) {
    ASSERT(scaling <= rect.w / minize_size_.first,
           "scaling(%f) > max scaling(%f)", scaling,
           rect.w / minize_size_.first);
    double width = minize_size_.first * scaling;
    double height = minize_size_.second;
    widget_->SetBound(rect.x + (rect.w - width) / 2,
                      rect.y + (rect.h - height) / 2, width, height);
  }
}

} // namespace core
} // namespace lexi