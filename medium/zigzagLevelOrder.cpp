/*  Given a binary tree, return the zigzag level order traversal of its nodes' values.
 *  (ie, from left to right, then right to left for the next level and alternate between).
 *
 *  For example:
 *  Given binary tree [3,9,20,null,null,15,7],
 *
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *
 *  return its zigzag level order traversal as:
 *
 *  [
 *    [3],
 *    [20,9],
 *    [15,7]
 *  ]
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
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> q;
    if (root) q.push(root);
    bool reverse = false;
    while (!q.empty()) {
      int size = q.size();
      std::vector<int> solve;
      for (int i = 0; i < size; i++) {
        auto node = q.front(); q.pop();
        solve.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (reverse) std::reverse(solve.begin(), solve.end());
      reverse = !reverse;
      res.push_back(solve);
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

  auto res = solute.zigzagLevelOrder(&node1);
  for (auto level : res) {
    for (auto i : level) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
