#include "core/window/layout/layout_vertical.hpp"
#include "common/log/lexi_log.hpp"
#include "core/window/layout/layout_node.hpp"
#include "layout_vertical.hpp"

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

auto LayoutVertical::SetAllowRect(const Rectd &rect, const double scaling)
    -> void {
  if (widget_ != nullptr && scaling >= 1) {
    ASSERT(scaling <= rect.h / minize_size_.second,
           "scaling(%f) > max scaling(%f)", scaling,
           rect.h / minize_size_.second);
    double width = minize_size_.first;
    double height = minize_size_.second * scaling;
    widget_->SetBound(rect.x + (rect.w - width) / 2,
                      rect.y + (rect.h - height) / 2, width, height);
  }
}

} // namespace core
} // namespace lexi