/*  Given a binary tree, flatten it to a linked list in-place.
 *  For example,
 *  Given
 *
 *       1
 *      / \
 *     2   5
 *    / \   \
 *   3   4   6
 *    
 *  The flattened tree should look like:
 *
 *   1
 *    \
 *     2
 *      \
 *       3
 *        \
 *         4
 *          \
 *           5
 *            \
 *             6
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
  void flatten(TreeNode *root) {
    while (root) {
      if (root->left && root->right) {
        auto t = root->left;
        while (t->right) t = t->right;
        t->right = root->right;
      }
      if (root->left) {
        root->right = root->left;
        root->left = NULL;
      }
      root = root->right;
    }
  }
};

int main() {
  Solution solute;
  TreeNode *root = new TreeNode(3);
  solute.flatten(root);
  return 0;
}
