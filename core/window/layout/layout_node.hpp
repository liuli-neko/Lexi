#pragma once

#include "common/utils.hpp"
#include "core/window/window.hpp"
#include <cstdint>
#include <vector>

namespace lexi {
namespace core {

class LayoutNode {
public:
  LayoutNode(Window *widget = nullptr);
  ~LayoutNode();
  virtual auto GetDefaultSize() -> std::pair<double, double>;
  virtual auto SetMinimizeSize(const std::pair<double, double> &size) -> void;
  virtual auto SetAllowRect(const Rectd &rect) -> void;
  inline auto GetLayoutMode() { return layout_mode; }

protected:
  Window *widget_;
  std::vector<LayoutNode *> childs_;
  enum {
    FREE_ZOOM = 0,
    SCALING_ZOOM = 1,
    FIXED_SIZE = 2,
    HORIZONTAL_ZOOM = 3,
    VERTICAL_ZOOM = 4
  } layout_mode;
  std::pair<double, double> minize_size_;
  Rectd rect_;
};

} // namespace core
} // namespace lexi