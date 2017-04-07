/*  Given a binary tree, find its minimum depth.
 *  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *  
 *  
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
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    std::queue<TreeNode *> q; q.push(root);
    int depth = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto node = q.front(); q.pop();
        if (!node->left && !node->right) return depth;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      depth++;
    }
    return depth;
  }
};

int main() {
  Solution solute;
  TreeNode *root = new TreeNode(3);
  auto res = solute.minDepth(root);
  std::cout << res << "\n";
  return 0;
}
