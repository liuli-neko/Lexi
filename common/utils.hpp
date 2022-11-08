#pragma once

#include <Btk/pixels.hpp>
#include <Btk/rect.hpp>

namespace lexi {

using Pointd = Btk::PointImpl<double>;
using StringView = Btk::u8string_view;
using Mat = Btk::PixBuffer;
using Color = Btk::Color;
using Rectd = Btk::RectImpl<double>;

enum LineType { SOLID_LINE = 0, DOTTED_LINE = 1, TYPE_SIZE = 2 };

} // namespace lexi