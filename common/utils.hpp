#pragma once

#include <cstddef>

#include <Btk/defs.hpp>
#include <Btk/painter.hpp>
#include <Btk/pixels.hpp>
#include <Btk/rect.hpp>
#include <Btk/string.hpp>

namespace lexi {

using Pointd = Btk::PointImpl<double>;
using StringView = Btk::u8string_view;
using String = Btk::u8string;
using uchar_t = Btk::uchar_t;
using Mat = Btk::PixBuffer;
using Color = Btk::Color;
using Rectd = Btk::RectImpl<double>;
using LineType = Btk::DashStyle;
using Painter = Btk::Painter;
using Pen = Btk::Pen;

} // namespace lexi