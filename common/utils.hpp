#pragma once

#include <Btk/painter.hpp>
#include <Btk/pixels.hpp>
#include <Btk/rect.hpp>

namespace lexi {

using Pointd = Btk::PointImpl<double>;
using StringView = Btk::u8string_view;
using Mat = Btk::PixBuffer;
using Color = Btk::Color;
using Rectd = Btk::RectImpl<double>;
using LineType = Btk::DashStyle;
using Painter = Btk::Painter;
using Pen = Btk::Pen;

} // namespace lexi