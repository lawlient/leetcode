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
#include <vector>
#include <array>
#include <math.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

// may be can try preorder search
public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    auto left = root->left, right = root->right;
    if (!left && !right) return true;
    auto l = right;
    if (left) {
      auto r = left;
      while (r->right) r = r->right;
      if (r->val >= root->val)
        return false;
    }
    if (!isValidBST(left)) return false;
    if (right) {
      while (l->left) l = l->left;
      if (l->val <= root->val)
        return false;
    }
    if (!isValidBST(right)) return false;
    return true;
  }
};

int main() {
  Solution solute;
  auto res = solute.isValidBST(nullptr);
  std::cout << res << "\n";
  return 0;
}
