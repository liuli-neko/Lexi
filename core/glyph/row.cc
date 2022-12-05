#include "row.hpp"

namespace lexi {
namespace core {
void Row::Draw(Window *win) {
  for (auto child : childs_) {
    child->Draw(win);
  }
}
}  // namespace core
}  // namespace lexi