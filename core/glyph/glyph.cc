#include "glyph.hpp"

#include <cstddef>
#include <iostream>

#include "common/log/lexi_log.hpp"
#include "core/checker/checker.hpp"

namespace lexi {
namespace core {

Glyph::Glyph() : parent_(nullptr), rect_(0, 0, 0, 0) { childs_.clear(); }

Glyph::~Glyph() {
  for (auto child : childs_) {
    if (child != nullptr) {
      delete child;
    }
    child = nullptr;
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

auto Glyph::Begin() -> TreeIterator { return TreeIterator(this); }
auto Glyph::End() -> TreeIterator { return TreeIterator(nullptr); }

auto preorder_traversal(const std::list<Glyph *> &values,
                        std::stack<Glyph *> *stack) -> void {
  for (auto iter = values.rbegin(); iter != values.rend(); ++iter) {
    preorder_traversal((*iter)->childs_, stack);
    stack->push(*iter);
  }
}

Glyph::TreeIterator::TreeIterator(Glyph *root) {
  if (root != nullptr) {
    preorder_traversal(root->childs_, &stack_);
    stack_.push(root);
  }
}

auto Glyph::TreeIterator::operator*() -> Glyph & { return *stack_.top(); }
auto Glyph::TreeIterator::operator++() -> void { stack_.pop(); }

auto Glyph::CheckMe(Checker checker) -> void { checker.CheckGlyph(this); }

auto Glyph::ToCharacter() -> String { return ""; }

auto Glyph::TreeIterator::operator++(int _) -> TreeIterator {
  ++(*this);
  return *this;
}

auto Glyph::TreeIterator::operator->() const -> Glyph * { return stack_.top(); }

auto Glyph::TreeIterator::operator==(const TreeIterator &iterator)
    -> bool const {
  return stack_ == iterator.stack_;
}

auto Glyph::TreeIterator::operator!=(const TreeIterator &iterator)
    -> bool const {
  return stack_ != iterator.stack_;
}

}  // namespace core
}  // namespace lexi