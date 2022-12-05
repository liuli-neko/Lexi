#pragma once

#include <stdint.h>

#include <algorithm>
#include <cstdlib>
#include <list>
#include <memory>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "common/algorithm/iterator.hpp"
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

class Checker;

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

 protected:
  class TreeIterator;

 public:
  virtual ~Glyph();
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

  /**
   * @brief 返回glyph图元的遍历器
   *
   * @return common::Iterator<Glyph *>
   */
  virtual auto Begin() -> TreeIterator;
  virtual auto End() -> TreeIterator;
  /**
   * @brief 调用语法检查类
   *
   * @param checker 语法检测工具
   */
  virtual auto CheckMe(Checker checker) -> void;

  /**
   * @brief 放回该图元对应的控制字符
   *
   * @return String 当前图元的字符表示，可以是字符，也可以是控制字符串。
   */
  virtual auto ToCharacter() -> String;

 protected:
  Glyph();

 protected:
  class TreeIterator {
   public:
    TreeIterator(Glyph *root);
    auto operator*() -> Glyph &;
    auto operator++() -> void;
    auto operator++(int) -> TreeIterator;
    auto operator--() -> void;
    auto operator--(int) -> TreeIterator;
    auto operator->() const -> Glyph *;
    auto operator==(const TreeIterator &iterator) -> bool const;
    auto operator!=(const TreeIterator &iterator) -> bool const;

   private:
    std::stack<Glyph *> stack_;
  };

 protected:
  std::list<Glyph *> childs_;
  Glyph *parent_;
  Rectd rect_;

  friend auto preorder_traversal(const std::list<Glyph *>& values,
                                 std::stack<Glyph *> *stack) -> void;
};

}  // namespace core
}  // namespace lexi