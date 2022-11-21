#pragma once

namespace lexi {
namespace common {
template <typename Container, typename T> class Iterator {
public:
  virtual auto operator*() -> T;
};
} // namespace common
} // namespace lexi