/*  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *  For example:
 *  Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7 
 *
 *  return its bottom-up level order traversal as:
 *  [
 *    [15,7],
 *    [9,20],
 *    [3]
 *  ]
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> q;
    if (root) q.push(root);
    while (!q.empty()) {
      int size = q.size();
      std::vector<int> one;
      for (int i = 0; i < size; i++) {
        auto t = q.front(); q.pop();
        one.push_back(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.insert(res.begin(), one);
    }
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode node1(1);
  auto res = solute.levelOrderBottom(&node1);
  // std::cout << res << "\n";
  return 0;
}
