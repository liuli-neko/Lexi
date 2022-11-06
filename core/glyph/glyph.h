#pragma once

#include <stdint.h>

#include <algorithm>
#include <deque>
#include <memory>
#include <unordered_map>
#include <vector>

#include "common/log/lexi_log.h"

namespace lexi {
namespace core {

class Window;
class Rect;
class Point;
/**
 * @brief Glyph
 * 用于定义富文本中各种可视化元素
 */
class Glyph {
 public:
  /**
   * @brief 插入一个图元到当前图元的子图元序列的index号位置
   *
   * @param glyph 待插入的图元
   * @param index 插入位置（下标从0开始，包括当前位置及后面的所有元素后移一位）
   */
  virtual auto Insert(std::shared_ptr<Glyph> glyph, int32_t index) -> void;
  /**
   * @brief 删除指定图元
   *
   * @param glyph 代删除的图元
   */
  virtual auto Remove(std::shared_ptr<Glyph> glyph) -> void;
  /**
   * @brief 查询编号为index的子节点
   *
   * @param index 代查询子节点编号
   * @return std::shared_ptr<Glyph> 查询的图元指针
   */
  virtual auto Child(int32_t index) -> std::shared_ptr<Glyph>;
  /**
   * @brief 查询父节点指针
   *
   * @return std::shared_ptr<Glyph> 父节点指针
   */
  virtual auto Parent() -> std::shared_ptr<Glyph>;
  /**
   * @brief 绘制当前图元
   *
   * @param win_imp 图元所在窗口的实例
   */
  virtual auto Draw(Window* win_imp) -> void;
  /**
   * @brief 图元的位置和大小
   *
   * @param rect 矩形
   */
  virtual auto Bounds(Rect* rect) -> void;
  /**
   * @brief 返回图元和点是否相交
   *
   * @param point 点
   * @return true 点在图元内
   * @return false 点不在图元内
   */
  virtual auto Intersects(const Point& point) -> bool;

 private:
  std::deque<std::shared_ptr<Glyph>> childs_;
  std::weak_ptr<Glyph> parent_;
};

}  // namespace core
}  // namespace lexi