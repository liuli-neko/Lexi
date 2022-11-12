#pragma once

#include "core/window/layout/layout_node.hpp"
#include "layout_fixed.hpp"
#include <vector>

namespace lexi {
namespace core {
class LayoutToolbar : public LayoutNode {
public:
  static constexpr auto HORIZONTAL = HORIZONTAL_ZOOM;
  static constexpr auto VERTICAL = VERTICAL_ZOOM;

public:
  virtual auto GetScalingSize(const double scaling) -> std::pair<double, double> override;
  auto AddTool(LayoutFixed *tool_iterm) -> void;
  auto SetLayoutMode(const LayoutMode layout_mode = HORIZONTAL) -> void;

private:
  std::vector<LayoutFixed *> tools_;
};
} // namespace core
} // namespace lexi