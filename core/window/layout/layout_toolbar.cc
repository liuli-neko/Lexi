#include "layout_toolbar.hpp"
#include <algorithm>
#include <utility>

namespace lexi {
namespace core {

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

auto LayoutToolbar::SetLayoutMode(const LayoutMode layout_mode) -> void {
  layout_mode_ = layout_mode;
}

} // namespace core
} // namespace lexi