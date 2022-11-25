#pragma once

namespace lexi {
namespace common {
template <typename Container, typename T> class Iterator {
public:
  virtual auto operator*() const -> T &;
  virtual auto operator++() -> void;
  virtual auto operator++(int) -> Iterator<Container, T>;
  virtual auto operator--() -> void;
  virtual auto operator--(int) -> Iterator<Container, T>;
  virtual auto operator->() const -> T *;
};
} // namespace common
} // namespace lexi