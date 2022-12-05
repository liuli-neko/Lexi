#pragma once

#include "core/glyph/glyph.hpp"

namespace lexi {
namespace core {
class Checker {
public:
  Checker(int argv, char **argc);
  ~Checker();
  virtual auto CheckGlyph(Glyph *glyph) -> void;
  virtual auto CheckCharacter(Glyph *glyph) -> void;
  virtual auto CheckRectangle(Glyph *glyph) -> void;
  virtual auto CheckPolyGon(Glyph *glyph) -> void;
  virtual auto CheckRow(Glyph *glyph) -> void;
};

Checker::Checker(int argv, char **argc) {}
auto Checker::CheckGlyph(Glyph *glyph) -> void {}
auto Checker::CheckCharacter(Glyph *glyph) -> void {}
auto Checker::CheckRectangle(Glyph *glyph) -> void {}
auto Checker::CheckPolyGon(Glyph *glyph) -> void {}
auto Checker::CheckRow(Glyph *glyph) -> void {}
Checker::~Checker() {}

} // namespace core
} // namespace lexi