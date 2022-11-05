#pragma once

#include "glyph.h"

namespace lexi {
namespace core {

class Row : public Glyph {
 public:
  void Insert(Glyph* glyph,int32_t index) override;
  void Draw(Window* win) override;
  bool Intersects(const Point& pt) override;
};

}  // namespace core
}  // namespace lexi