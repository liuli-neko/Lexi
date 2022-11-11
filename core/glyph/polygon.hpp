#pragma once

#include "common/utils.hpp"
#include "glyph.hpp"
#include <vector>

namespace lexi {
namespace core {

class Polygon : public Glyph {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Polygon);

public:
  auto Draw(Window *win) -> void override;
  auto SetPoints(const std::vector<Pointd> &points) -> void;

private:
  std::vector<Pointd> points_;
};

} // namespace core
} // namespace lexi