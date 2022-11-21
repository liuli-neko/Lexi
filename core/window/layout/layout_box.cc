#include "layout_box.hpp"

#include <cstddef>
#include <utility>

#include "common/log/lexi_log.hpp"
#include "core/window/layout/layout_node.hpp"
#include "core/window/window.hpp"

namespace lexi {
namespace core {

namespace {
class Tree {
 public:
  Tree();
  auto Add(LayoutNode *node, LayoutNode *container, const LayoutBox::AREA area)
      -> void;
  auto Remove(LayoutNode *node) -> void;
  auto GetScalingSize(const double scaling) -> std::pair<double, double>;
  auto SetAllowRect(const Rectd &rect, const double sclaing) -> void;

 private:
  struct Node {
    LayoutNode *node = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *top = nullptr;
    Node *below = nullptr;
    std::set<LayoutNode *> sub_tree_nodes;
    auto GetScalingSize(const double scaling) -> std::pair<double, double>;
    auto SetAllowRect(const Rectd &rect, const double sclaing) -> void;
    ~Node();
  } root_;

 private:
  auto insert(Node *root, LayoutNode *node, LayoutNode *container,
              const LayoutBox::AREA area) -> void;
  auto remove(Node *root, LayoutNode *node) -> void;
};
}  // namespace

LayoutBox::LayoutBox(Window *widget) : LayoutNode(widget) {
  node_tree_ = new Tree;
}

LayoutBox::~LayoutBox() { delete node_tree_; }

auto LayoutBox::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  return node_tree_->GetScalingSize(scaling);
}

auto LayoutBox::AddWidget(LayoutNode *node, LayoutNode *container,
                          const AREA area) -> void {
  node_tree_->Add(node, container, area);
}

auto LayoutBox::RemoveWidget(LayoutNode *node) -> void {
  node_tree_->Remove(node);
}

auto Tree::Node::SetAllowRect(const Rectd &rect, const double scaling) -> void {
  if (node != nullptr) {
    return node->SetAllowRect(rect, scaling);
  }
  if (top != nullptr && below != nullptr) {
    top->SetAllowRect({rect.x, rect.y, rect.w, rect.h / 2}, scaling / 2);
    below->SetAllowRect({rect.x, rect.y + rect.h / 2, rect.w, rect.h / 2},
                        scaling / 2);
  } else if (right != nullptr && left != nullptr) {
    left->SetAllowRect({rect.x, rect.y, rect.w / 2, rect.h}, scaling / 2);
    right->SetAllowRect({rect.x + rect.w / 2, rect.y, rect.w / 2, rect.h},
                        scaling / 2);
  }
}

auto Tree::SetAllowRect(const Rectd &rect, const double scaling) -> void {
  root_.SetAllowRect(rect, scaling);
}

auto LayoutBox::SetAllowRect(const Rectd &rect, const double scaling) -> void {
  node_tree_->SetAllowRect(rect, scaling);
}

Tree::Tree() {}

auto Tree::insert(Tree::Node *root, LayoutNode *node, LayoutNode *container,
                  const LayoutBox::AREA area) -> void {
  if (root->sub_tree_nodes.size() < 1) {
    if (root->node == nullptr) {
      root->node = node;
      root->sub_tree_nodes.insert(node);
    } else {
      switch (area) {
        case LayoutBox::AREA::TOP:
          root->below = new Tree::Node;
          root->below->node = root->node;
          root->below->sub_tree_nodes.insert(root->node);
          root->top = new Tree::Node;
          root->top->node = node;
          root->top->sub_tree_nodes.insert(node);
          break;
        case LayoutBox::AREA::BELOW:
          root->below = new Tree::Node;
          root->below->node = node;
          root->below->sub_tree_nodes.insert(node);
          root->top = new Tree::Node;
          root->top->node = root->node;
          root->top->sub_tree_nodes.insert(root->node);
          break;
        case LayoutBox::AREA::LEFT:
          root->left = new Tree::Node;
          root->left->node = node;
          root->left->sub_tree_nodes.insert(node);
          root->right = new Tree::Node;
          root->right->node = root->node;
          root->right->sub_tree_nodes.insert(root->node);
          break;
        case LayoutBox::AREA::RIGHT:
          root->left = new Tree::Node;
          root->left->node = root->node;
          root->left->sub_tree_nodes.insert(root->node);
          root->right = new Tree::Node;
          root->right->node = node;
          root->right->sub_tree_nodes.insert(node);
          break;
      }
      root->sub_tree_nodes.erase(root->node);
      root->node = nullptr;
    }
  } else if (root->top->sub_tree_nodes.count(container) > 0) {
    root->top->sub_tree_nodes.insert(node);
    insert(root->top, node, container, area);
  } else if (root->below->sub_tree_nodes.count(container) > 0) {
    root->below->sub_tree_nodes.insert(node);
    insert(root->below, node, container, area);
  } else if (root->left->sub_tree_nodes.count(container) > 0) {
    root->left->sub_tree_nodes.insert(node);
    insert(root->left, node, container, area);
  } else if (root->right->sub_tree_nodes.count(container) > 0) {
    root->right->sub_tree_nodes.insert(node);
    insert(root->right, node, container, area);
  }
}

auto Tree::Add(LayoutNode *node, LayoutNode *container,
               const LayoutBox::AREA area) -> void {
  insert(&root_, node, container, area);
}

auto Tree::remove(Tree::Node *root, LayoutNode *node) -> void {
  root->sub_tree_nodes.erase(node);
  Tree::Node *tmp = nullptr;
  if (root->top != nullptr && root->top->node == node) {
    delete root->top;
    tmp = root->below;
  } else if (root->below != nullptr && root->below->node == node) {
    delete root->below;
    tmp = root->top;
  } else if (root->right != nullptr && root->right->node == node) {
    delete root->right;
    tmp = root->left;
  } else if (root->left != nullptr && root->left->node == node) {
    delete root->left;
    tmp = root->right;
  } else {
    if (root->top != nullptr && root->top->sub_tree_nodes.count(node) > 0) {
      remove(root->top, node);
    } else if (root->below != nullptr &&
               root->below->sub_tree_nodes.count(node) > 0) {
      remove(root->below, node);
    } else if (root->right != nullptr &&
               root->right->sub_tree_nodes.count(node) > 0) {
      remove(root->right, node);
    } else if (root->left != nullptr &&
               root->left->sub_tree_nodes.count(node) > 0) {
      remove(root->left, node);
    }
  }
  if (tmp != nullptr) {
    (*root) = (*tmp);
    delete tmp;
  }
}

auto Tree::Remove(LayoutNode *node) -> void {
  if (root_.sub_tree_nodes.count(node)) {
    remove(&root_, node);
  }
}

Tree::Node::~Node() {
  if (top != nullptr) {
    delete top;
  }
  if (below != nullptr) {
    delete below;
  }
  if (left != nullptr) {
    delete left;
  }
  if (right != nullptr) {
    delete right;
  }
}

auto Tree::Node::GetScalingSize(const double scaling)
    -> std::pair<double, double> {
  if (node != nullptr) {
    return node->GetScalingSize(scaling);
  }
  if (top != nullptr && below != nullptr) {
    auto top_size = top->GetScalingSize(scaling / 2);
    auto below_size = below->GetScalingSize(scaling / 2);
    return std::make_pair(top_size.first + below_size.first,
                          top_size.second + below_size.second);
  } else if (right != nullptr && left != nullptr) {
    auto right_size = right->GetScalingSize(scaling / 2);
    auto left_size = left->GetScalingSize(scaling / 2);
    return std::make_pair(right_size.first + left_size.first,
                          right_size.second + left_size.second);
  }
  ASSERT(false, "node tree error");
}

auto Tree::GetScalingSize(const double scaling) -> std::pair<double, double> {
  return root_.GetScalingSize(scaling);
}

}  // namespace core
}  // namespace lexi