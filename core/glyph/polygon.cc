#pragma once

#include "polygon.hpp"
#include <cstdint>

namespace lexi {
namespace core {

auto Polygon::Draw(Window *win) -> void {
  win->DrawRect(rect_);
  int len = points_.size();
  for (int32_t i = 0; i < len; i++) {
    win->DrawLine(points_[(i - 1 + len) % len], points_[i]);
  }
}

auto Polygon::SetPoints(const std::vector<Pointd> &points) -> void {
  points_ = points;
}

} // namespace core
} // namespace lexi