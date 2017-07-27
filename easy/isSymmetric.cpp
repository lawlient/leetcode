/*  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *  For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 *      1
 *     / \
 *    2   2
 *   / \ / \
 *  3  4 4  3
 *
 *  But the following [1,2,2,null,3,null,3] is not:
 *
 *      1
 *     / \
 *    2   2
 *     \   \
 *     3    3
 *
 *  Note:
 *  Bonus points if you could solve it both recursively and iteratively. 
 * 
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <math.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return isSymmetric(left->right, right->left) &&
           isSymmetric(left->left, right->right);
  }
public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    std::queue<TreeNode *> l, r;
    l.push(root->left);
    r.push(root->right);
    while (!l.empty() && !r.empty()) {
      auto left = l.front(); l.pop();
      auto right = r.front(); r.pop();
      if (!left && !right) continue;
      if (!left || !right) return false;
      if (left->val != right->val) return false;
      l.push(left->left);
      l.push(left->right);
      r.push(right->right);
      r.push(right->left);
    }
    return true;
  }

  bool isSymmetricRec(TreeNode *root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
  }
};

int main() {
  Solution solute;
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(2);
  node1.left = &node2;
  node1.right = &node3;

  auto res = solute.isSymmetricRec(&node1);
  std::cout << res << "\n";
  return 0;
}
