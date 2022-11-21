#pragma once

#include <set>
#include <utility>

#include "common/utils.hpp"
#include "core/window/window.hpp"
#include "layout_node.hpp"

namespace lexi {
namespace core {

namespace {
class Tree;
} // namespace

class LayoutBox : public LayoutNode {
public:
  enum AREA { LEFT = 0, RIGHT = 1, TOP = 2, BELOW = 3 };

public:
  LayoutBox(Window *widget = nullptr);
  ~LayoutBox();
  virtual auto GetScalingSize(const double scaling)
      -> std::pair<double, double> override;
  auto AddWidget(LayoutNode *node, LayoutNode *container, const AREA area)
      -> void;
  auto RemoveWidget(LayoutNode *node) -> void;
  auto SetAllowRect(const Rectd &rect, const double scaling) -> void override;

private:
  Tree *node_tree_;
};

} // namespace core
} // namespace lexi