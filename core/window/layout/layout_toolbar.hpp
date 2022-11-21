#pragma once

#include "common/utils.hpp"
#include "core/window/layout/layout_node.hpp"
#include "core/window/window.hpp"
#include "layout_fixed.hpp"
#include <list>

namespace lexi {
namespace core {
class LayoutToolbar : public LayoutNode {
public:
  static constexpr auto HORIZONTAL = HORIZONTAL_ZOOM;
  static constexpr auto VERTICAL = VERTICAL_ZOOM;

public:
  LayoutToolbar(Window *widget = nullptr);
  virtual auto GetScalingSize(const double scaling)
      -> std::pair<double, double> override;
  auto AddTool(LayoutFixed *tool_iterm) -> void;
  auto RemoveTool(LayoutFixed *tool_iterm) -> void;
  auto SetLayoutMode(const LayoutMode layout_mode = HORIZONTAL) -> void;
  auto SetAllowRect(const Rectd &rect, const double scaling) -> void override;

private:
  std::list<LayoutFixed *> tools_;
};
} // namespace core
} // namespace lexi