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

  // it is wrong
  bool isValidBST2(TreeNode *root) {
    std::stack<TreeNode *> visit;
    if (root) visit.push(root);
    int min = INT_MIN;
    while (!visit.empty()) {
      auto node = visit.top();
      if (node->left) {
        visit.push(node->left);
        continue;
      }
      if (node->val <= min)
        return false;
      min = node->val;
      visit.pop();
      if (node->right) visit.push(node->right);
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
