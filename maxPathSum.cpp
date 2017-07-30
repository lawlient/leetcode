/*  Given a binary tree, find the maximum path sum.  
 *  For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 *  The path must contain at least one node and does not need to go through the root.  
 *
 *  For example: 
 *  Given the below binary tree,
 *
 *     1
 *    / \
 *   2   3
 *
 *   Return 6. 
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
  void help(TreeNode *root) {
    if (!root) return;
    if (!root->left && !root->right)
      index[root].first = index[root].second = root->val;
    if (root->left) {
      help(root->left);
      index[root].first = std::max(index[root->left].first, index[root->left].second) + root->val;
    }
    if (root->right) {
      help(root->right);
      index[root].second = std::max(index[root->right].first, index[root->right].second) + root->val;
    }
    int s = index[root].first + index[root].second - root->val;
    int half = std::max(index[root].first, index[root->right].second);
    int all  = std::max(half, s);
    max = std::max(max, all);
  }

  int max;
  std::map<TreeNode *, std::pair<int, int>> index;
public:
  int maxPathSum(TreeNode *root) {
    max = 0;
    help(root);
    return max;
  }
};
