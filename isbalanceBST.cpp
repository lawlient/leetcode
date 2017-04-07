/*  Given a binary tree, determine if it is height-balanced.
 *  For this problem, a height-balanced binary tree is defined as a binary tree in which
 *  the depth of the two subtrees of every node never differ by more than 1. 
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
  int depthBalance(TreeNode *root) {
    if (root == nullptr) return 0;
    int ldepth = depthBalance(root->left);
    if (ldepth == -1) return -1;
    int rdepth = depthBalance(root->right);
    if (rdepth == -1) return -1;

    if (std::abs(ldepth - rdepth) > 1) return -1;
    return std::max(ldepth, rdepth) + 1;
  }
public:
  bool isBalanced(TreeNode *root) {
    return depthBalance(root) != -1;
  }
};

int main() {
  Solution solute;
  TreeNode *root = new TreeNode(3);
  auto res = solute.isBalanced(root);
  std::cout << res << "\n";
  return 0;
}
