#pragma once

#include "common/utils.hpp"
#include "core/window/window.hpp"
#include <cstdint>
#include <vector>

namespace lexi {
namespace core {

class LayoutNode {
protected:
  Window *widget_;
  enum LayoutMode {
    FREE_ZOOM = 0,
    SCALING_ZOOM = 1,
    FIXED_SIZE = 2,
    HORIZONTAL_ZOOM = 3,
    VERTICAL_ZOOM = 4
  } layout_mode_;
  std::pair<double, double> minize_size_;
  Rectd rect_;

public:
  LayoutNode(Window *widget = nullptr);
  virtual auto GetScalingSize(const double scaling = 1)
      -> std::pair<double, double>;
  virtual auto SetMinimizeSize(const std::pair<double, double> &size) -> void;
  virtual auto SetAllowRect(const Rectd &rect, const double scaling) -> void;
  virtual auto GetLayoutMode() -> LayoutMode;
};

} // namespace core
} // namespace lexi