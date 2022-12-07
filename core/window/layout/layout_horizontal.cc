#include "layout_horizontal.hpp"

#include "common/log/lexi_log.hpp"
#include "core/window/layout/layout_node.hpp"

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
auto LayoutHorizontal::SetAllowRect(const Rectd &rect, const double scaling)
    -> void {
  if (widget_ != nullptr && scaling >= 1) {
    ASSERT(scaling <= rect.w / minize_size_.first)
        << "scaling(" << scaling << ") > max scaling("
        << rect.w / minize_size_.first << ")";
    double width = minize_size_.first * scaling;
    double height = minize_size_.second;
    widget_->SetBound(rect.x + (rect.w - width) / 2,
                      rect.y + (rect.h - height) / 2, width, height);
  }
}

}  // namespace core
}  // namespace lexi