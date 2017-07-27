/*  Given a binary tree, find its maximum depth.
 *  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int main() {
  Solution solute;
  TreeNode node1(1);
  auto res = solute.maxDepth(&node1);
  std::cout << res << "\n";
  return 0;
}
