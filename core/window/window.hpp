#pragma once

#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <Btk/widget.hpp>

#include "common/utils.hpp"

namespace lexi {
namespace core {

class Window : public Btk::Widget {
 public:
  Window();
  ~Window();
  virtual auto DrawRect(const Rectd &rect) const -> void;
  virtual auto DrawString(StringView str, const Rectd &rect,
                          const double offset_x = 2,
                          const double offset_y = 3) const -> void;
  virtual auto DrawImg(const Mat &img, const Rectd &rect) const -> void;
  virtual auto DrawLine(const Pointd &x, const Pointd &y) const -> void;
  virtual auto SetPainterColor(const Color &color) -> void;
  virtual auto SetBound(const Rectd &rect) -> void;
  virtual auto SetBound(const double x, const double y, const double w,
                        const double h) -> void;

 private:
  Painter *painter_;
  Pen *pen_;
};

}  // namespace core
}  // namespace lexi
