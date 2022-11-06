#include "glyph.h"

namespace lexi {
namespace core {
auto Glyph::Insert(std::shared_ptr<Glyph> glyph, int32_t index) -> void {
  if (index <= 0) {
    childs_.push_front(glyph);
  } else if (index >= childs_.size()) {
    childs_.push_back(glyph);
  } else {
    childs_.insert(childs_.begin() + index, glyph);
  }
}
auto Glyph::Remove(std::shared_ptr<Glyph> glyph) -> void {
  auto it = std::find(childs_.begin(), childs_.end(), glyph);
  if (it == childs_.end()) {
    LOG_WARN("Remove failed! the glyph is not in this!!!");
    return;
  }
  childs_.erase(it);
}
auto Glyph::Child(int32_t index) -> std::shared_ptr<Glyph> {
    return *(childs_.begin() + index);
}
auto Glyph::Parent() -> std::shared_ptr<Glyph> {}
auto Glyph::Draw(Window* win_imp) -> void {}
auto Glyph::Bounds(Rect* rect) -> void {}
auto Glyph::Intersects(const Point& point) -> bool {}
}  // namespace core
}  // namespace lexi