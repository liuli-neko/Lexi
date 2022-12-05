#include "block.hpp"

namespace lexi {
namespace core {
auto Block::Draw(Window* win) -> void {
  for (const auto& child : childs_) {
    child->Draw(win);
  }
}

}  // namespace core
}  // namespace lexi