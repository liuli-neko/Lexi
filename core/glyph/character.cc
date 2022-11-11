#pragma once

#include "character.hpp"

namespace lexi {
namespace core {

auto Character::Draw(Window *win) -> void {
  win->DrawString(String::from(&character_, 1), rect_);
}

} // namespace core
} // namespace lexi