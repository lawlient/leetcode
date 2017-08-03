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
    if (!root->left && !root->right) {
      index[root].first = index[root].second = root->val;
      max = std::max(max, root->val);
      return;
    }
    auto lc = root->left;
    auto rc = root->right;
    if (lc) {
      help(lc);
      int maxlChild = std::max(index[lc].first, index[lc].second);
      index[root].first = root->val + (maxlChild > 0 ? maxlChild : 0);
    } else {
      index[root].first = root->val;
    }
    if (rc) {
      help(rc);
      int maxrChild = std::max(index[rc].first, index[rc].second);
      index[root].second = root->val + (maxrChild > 0 ? maxrChild : 0);
    } else {
      index[root].second = root->val;
    }
    max = std::max(max, root->val);
    max = std::max(max, index[root].first);
    max = std::max(max, index[root].second);
    max = std::max(max, index[root].first + index[root].second - root->val);
  }

  int max;
  std::map<TreeNode *, std::pair<int, int>> index;
public:
  int maxPathSum(TreeNode *root) {
    if (!root) return 0;
    max = INT_MIN;
    help(root);
    return max;
  }
};

int main() {
  auto tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  std::cout << Solution().maxPathSum(tree) << std::endl;
  return 0;
}
