#include "layout_toolbar.hpp"
#include "common/log/lexi_log.hpp"
#include "core/window/window.hpp"
#include <algorithm>
#include <utility>

namespace lexi {
namespace core {

LayoutToolbar::LayoutToolbar(Window *widget) : LayoutNode(widget) {
  layout_mode_ = HORIZONTAL;
}

auto LayoutToolbar::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  double width = 0, height = 0;
  if (layout_mode_ == HORIZONTAL) {
    for (auto &tool : tools_) {
      const auto &size = tool->GetScalingSize(scaling);
      width += size.first;
      height = std::max(size.second, height);
    }
  } else if (layout_mode_ == VERTICAL) {
    for (auto &tool : tools_) {
      const auto &size = tool->GetScalingSize(scaling);
      width = std::max(size.first, width);
      height += height;
    }
  }
  return std::make_pair(width, height);
}

auto LayoutToolbar::AddTool(LayoutFixed *tool_iterm) -> void {
  tools_.push_back(tool_iterm);
}

auto LayoutToolbar::RemoveTool(LayoutFixed *tool_iterm) -> void {
  tools_.remove(tool_iterm);
}

auto LayoutToolbar::SetLayoutMode(const LayoutMode layout_mode) -> void {
  layout_mode_ = layout_mode;
}

auto LayoutToolbar::SetAllowRect(const Rectd &rect, const double scaling)
    -> void {
  if (widget_ != nullptr && scaling > 1) {
    widget_->SetBound(rect);
    widget_->Show();
    double x = rect.x;
    double y = rect.y;
    for (auto &tool_iterm : tools_) {
      auto size = tool_iterm->GetScalingSize(scaling);
      tool_iterm->SetAllowRect(
          {x, y, scaling * size.first, scaling * size.second}, scaling);
      if (layout_mode_ == HORIZONTAL) {
        x += scaling * size.first;
      } else if (layout_mode_ == VERTICAL) {
        y += scaling * size.second;
      } else {
        ASSERT(false, "undefined policy");
      }
    }
  }
}

} // namespace core
} // namespace lexi