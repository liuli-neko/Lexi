#include "layout_scaling.hpp"
#include "common/log/lexi_log.hpp"
#include "core/window/layout/layout_node.hpp"

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
auto LayoutScaling::SetAllowRect(const Rectd &rect, const double scaling)
    -> void {
  if (widget_ != nullptr && scaling >= 1) {
    double scaling_ =
        std::min(rect.w / minize_size_.first, rect.h / minize_size_.second);
    ASSERT(scaling <= scaling_, "scaling(%f) > max scaling(%f)", scaling,
           scaling_);
    double width = minize_size_.first * scaling;
    double height = minize_size_.second * scaling;
    widget_->SetBound(rect.x + (rect.w - width) / 2,
                      rect.y + (rect.h - height) / 2, width, height);
  }
}

} // namespace core
} // namespace lexi