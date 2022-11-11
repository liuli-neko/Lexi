#include "layout_node.hpp"
#include "common/utils.hpp"

namespace lexi {
namespace core {

LayoutNode::LayoutNode(Window *widget) : widget_(widget) {
  childs_.clear();
  rect_ = Rectd(-1, -1, -1, -1);
  minize_size_ = {-1, -1};
  layout_mode = FREE_ZOOM;
}

LayoutNode::~LayoutNode() {
  for (auto &child : childs_) {
    delete child;
  }
}

auto LayoutNode::GetDefaultSize() -> std::pair<double, double> {
  if (fabs(rect_.x + 1) > 1e-8 && fabs(rect_.y + 1) > 1e-8) {
    if (rect_.x > minize_size_.first && rect_.y > minize_size_.second) {
      return std::make_pair(rect_.x, rect_.y);
    }
  }
  return minize_size_;
}

auto LayoutNode::SetMinimizeSize(const std::pair<double, double> &size)
    -> void {
  minize_size_ = size;
}

auto LayoutNode::SetAllowRect(const Rectd &rect) -> void { rect_ = rect; }

} // namespace core
} // namespace lexi