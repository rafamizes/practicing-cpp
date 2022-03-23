#include <iostream>

struct Node {
  struct Simblings {
    Node *right = nullptr;
    Node *left = nullptr;
  };
  explicit Node(int val) noexcept
      : Node{val, {.right = nullptr, .left = nullptr}} {}

  Node(int val, Simblings children) noexcept : _val{val}, _children{children} {}
  int val() const noexcept { return _val; }
  Node *right() const noexcept { return _children.right; }
  Node *left() const noexcept { return _children.left; }

 private:
  const int _val;
  const Simblings _children;
};

/// helper recursive function.
// It returns the highest printed depth (level).
int printRightRec(Node *node, int currDepth, int highestPrintedDepth);

/// Starts from root
void printRight(Node *root);
int main() {
  Node nine{9};
  Node eight{8};
  Node seven{7, {.left = &nine}};
  Node six{6, {.right = &eight, .left = &seven}};
  Node four{4};
  Node five{5, {.right = &six}};
  Node two{2};
  Node three{3, {.right = &four, .left = &five}};
  /* Node root{1, &two, &three}; */
  Node root{1, {.right = &three, .left = &two}};
  printRight(&root);
  return 0;
}
int printRightRec(Node *node, int currDepth, int highestPrintedDepth) {
  if (node == nullptr)
    return highestPrintedDepth;

  if (currDepth > highestPrintedDepth) {
    std::cout << node->val() << "\n";
    highestPrintedDepth = currDepth;
  }
  highestPrintedDepth =
      printRightRec(node->right(), currDepth + 1, highestPrintedDepth);
  return printRightRec(node->left(), currDepth + 1, highestPrintedDepth);
}
/// Starts from root
void printRight(Node *root) {
  int highestPrintedDepth = -1;
  printRightRec(root, 0, highestPrintedDepth);
}
