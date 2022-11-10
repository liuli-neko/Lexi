#pragma once

#include <algorithm>
#include <cstdlib>
#include <list>
#include <memory>
#include <stdint.h>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "common/log/lexi_log.hpp"
#include "core/window/window.hpp"

// clang-format off
#define DEFINE_GLYPH_CLASS_ONLY_BY_NEW(class_name)                             \
public :                                                                       \
  static auto New()-> class_name* {                                            \
    if constexpr(!std::is_abstract<class_name>::value){                        \
    return new class_name;                                                     \
    } else {                                                                   \
      abort();                                                                 \
    }                                                                          \
  }
// clang-format on

namespace lexi {
namespace core {

class HeapObject {
protected:
  HeapObject() = default;
};

/**
 * @brief Glyph
 * 用于定义富文本中各种可视化元素
 */
class Glyph : public HeapObject {
  DEFINE_GLYPH_CLASS_ONLY_BY_NEW(Glyph);

public:
  ~Glyph();
  /**
   * @brief 插入一个图元到当前图元的子图元序列的index号位置
   *
   * @param glyph 待插入的图元
   * @param index 插入位置（下标从0开始，包括当前位置及后面的所有元素后移一位）
   */
  virtual auto Insert(Glyph *glyph, int32_t index) -> void;
  /**
   * @brief 删除指定图元
   *
   * @param glyph 代删除的图元
   */
  virtual auto Remove(Glyph *glyph) -> void;
  /**
   * @brief 查询编号为index的子节点
   *
   * @param index 代查询子节点编号
   * @return Glyph* 查询的图元指针
   */
  virtual auto Child(int32_t index) -> Glyph *;
  /**
   * @brief 查询父节点指针
   *
   * @return Glyph* 父节点指针
   */
  virtual auto Parent() -> Glyph *;
  /**
   * @brief 绘制当前图元
   *
   * @param win_imp 图元所在窗口的实例
   */
  virtual auto Draw(Window *win_imp) -> void;
  /**
   * @brief 图元的位置和大小
   *
   * @param rect 矩形
   */
  virtual auto Bounds(Rectd *rect) -> void;
  /**
   * @brief 返回图元和点是否相交
   *
   * @param point 点
   * @return true 点在图元内
   * @return false 点不在图元内
   */
  virtual auto Intersects(const Pointd &point) -> bool;

protected:
  Glyph();

protected:
  std::list<Glyph *> childs_;
  Glyph *parent_;
  Rectd rect_;
};

} // namespace core
} // namespace lexi