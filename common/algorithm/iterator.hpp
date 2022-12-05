#pragma once

namespace lexi {
namespace common {
template <typename T>
class Iterator {
 public:
  virtual auto operator*() -> T &{};
  virtual auto operator++() -> void{};
  virtual auto operator++(int) -> Iterator<T>{};
  virtual auto operator--() -> void{};
  virtual auto operator--(int) -> Iterator<T>{};
  virtual auto operator->() const -> T *{};
  virtual auto operator==(Iterator<T>) const -> bool{};
  virtual auto IsDone() const -> bool{};
};

}  // namespace common
}  // namespace lexi