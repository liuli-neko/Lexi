#pragma once
#include "character.hpp"

#include <iostream>

namespace lexi {
namespace core {

auto Character::Draw(Window *win) -> void {
  win->DrawString(String::from(&character_, 1), rect_);
}

auto Character::ToCharacter() -> String { return String::from(&character_, 1); }

auto Character::SetValue(uchar_t ch) -> void { character_ = ch; }

Character::Character(uchar_t ch) : character_(ch), Glyph() {}

Character::~Character() {
  LOG << "delete CharacterGlyph[" << this << "]:{" << ToCharacter() << "}";
}

}  // namespace core
}  // namespace lexi