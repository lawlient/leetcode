/*  Given a binary tree, determine if it is a valid binary search tree (BST).
 *  Assume a BST is defined as follows:
 *  
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 *  
 *  Example 1:
 *    2
 *   / \
 *  1   3
 *
 *  Binary tree [2,1,3], return true.
 *  
 *  Example 2:
 *    1
 *   / \
 *  2   3
 *
 *  Binary tree [1,2,3], return false. 
 *
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <stack>
#include <array>
#include <math.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

// may be can try inorder search
public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    if (root->left) {
      auto p = root->left;
      while (p->right) p = p->right;
      if (p->val >= root->val)
        return false;
      if (!isValidBST(root->left))
        return false;
    }

    if (root->right) {
      auto p = root->right;
      while (p->left) p = p->left;
      if (p->val <= root->val)
        return false;
      if (!isValidBST(root->right))
        return false;
    }
    return true;
  }

  // inorder visit, the number should be increasing
  bool isValidBST2(TreeNode *root) {
    std::stack<TreeNode *> visit;
    long min = LONG_MIN;
    while (root || !visit.empty()) {
      if (root) {
        visit.push(root);
        root = root->left;
        continue;
      }
      root = visit.top();
      visit.pop();
      if (root->val <= min)
        return false;
      min = root->val;
      root = root->right;
    }
    return true;
  }
};

int main() {
  Solution solute;
  auto res = solute.isValidBST(nullptr);
  std::cout << res << "\n";
  return 0;
}
