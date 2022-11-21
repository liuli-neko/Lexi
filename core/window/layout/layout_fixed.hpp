#pragma once

#include "core/window/window.hpp"
#include "layout_node.hpp"

namespace lexi {
namespace core {

class LayoutFixed : public LayoutNode {
public:
  LayoutFixed(Window *wigdet = nullptr);
  auto GetScalingSize(const double scaling = 1)
      -> std::pair<double, double> override;
  auto SetAllowRect(const Rectd &rect, const double scaling) -> void override;
};

} // namespace core
} // namespace lexi