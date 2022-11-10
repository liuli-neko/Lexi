#include "glyph.hpp"
#include <cstddef>

namespace lexi {
namespace core {

Glyph::Glyph() { parent_ = nullptr; }

Glyph::~Glyph() {
  for (auto &child : childs_) {
    delete child;
  }
}

auto Glyph::Insert(Glyph *glyph, int32_t index) -> void {
  if (index <= 0) {
    childs_.push_front(glyph);
  } else if (index >= childs_.size()) {
    childs_.push_back(glyph);
  } else {
    childs_.insert(std::next(childs_.begin(), index), glyph);
  }
  glyph->parent_ = this;
}

auto Glyph::Remove(Glyph *glyph) -> void {
  auto it = std::find(childs_.begin(), childs_.end(), glyph);
  if (it == childs_.end()) {
    LOG_WARN("Remove failed! the glyph is not in this!!!");
    return;
  }
  (*it)->parent_ = nullptr;
  childs_.erase(it);
}

auto Glyph::Child(int32_t index) -> Glyph * {
  return *std::next(childs_.begin(), index);
}

auto Glyph::Parent() -> Glyph * { return parent_; }

auto Glyph::Draw(Window *win_imp) -> void { win_imp->DrawRect(rect_); }

auto Glyph::Bounds(Rectd *rect) -> void { rect_ = *rect; }

auto Glyph::Intersects(const Pointd &point) -> bool {
  if (point.x >= rect_.x && point.x <= rect_.x + rect_.w &&
      point.y >= rect_.y && point.y <= rect_.y + rect_.h) {
    return true;
  }
  return false;
}

} // namespace core
} // namespace lexi