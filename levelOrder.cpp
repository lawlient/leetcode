/*  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *  For example:
 *  Given binary tree [3,9,20,null,null,15,7],
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 *  return its level order traversal as:
 *  [
 *    [3],
 *    [9,20],
 *    [15,7]
 *  ]
 *  
 *  
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
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    if (!root) return res;
    res.push_back(std::vector<int>(1, root->val));
    std::queue<TreeNode *> q;
    if (root->left) q.push(root->left);
    if (root->right) q.push(root->right);
    int size = q.size();
    std::vector<int> oneL;
    for (int i = 0; i < size; i++) {
      auto node = q.front(); q.pop();
      oneL.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
      if (i+1 == size) {
        res.push_back(oneL);
        oneL.clear();
        size = q.size();
        i = -1;
      }
    }
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(2);
  node1.left = &node2;
  node1.right = &node3;

  auto res = solute.levelOrder(&node1);
  for (auto level : res) {
    for (auto i : level) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
