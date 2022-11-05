#pragma once

#include <stdint.h>

#include <vector>

namespace lexi {
namespace core {

class Window;
class Rect;
class Point;

class Glyph {
 public:
  virtual void Insert(Glyph*, int32_t);
  virtual void Remove(Glyph*);
  virtual Glyph* Child(int32_t);
  virtual Glyph* Parent();
  virtual void Draw(Window*);
  virtual void Bounds(Rect*);
  virtual bool Intersects(const Point&);

};

void test() { std::vector<int> a; }

}  // namespace core
}  // namespace lexi