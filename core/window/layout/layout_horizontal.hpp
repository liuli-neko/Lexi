#pragma once

#include "core/window/window.hpp"
#include "layout_node.hpp"

namespace lexi {
namespace core {

class LayoutHorizontal : public LayoutNode {
public:
  LayoutHorizontal(Window *wigdet = nullptr);
  auto GetScalingSize(const double scaling = 1) -> std::pair<double, double> override;
};

} // namespace core
} // namespace lexi