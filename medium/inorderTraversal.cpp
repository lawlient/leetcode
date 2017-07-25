/*  Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *  For example:
 *  Given binary tree [1,null,2,3],
 *  1
 *   \
 *    2
 *   /
 *  3
 *  return [1,3,2]. 
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
  void help(TreeNode *root, std::vector<int> &res) {
    if (!root) return;
    if (root->left) help(root->left, res);
    res.push_back(root->val);
    if (root->right) help(root->right, res);
  }
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    help(root, res);
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode input(1);
  TreeNode right(2);
  input.right = &right;
  TreeNode left(3);
  right.left = &left;
  auto res = solute.inorderTraversal(&input);
  for (auto i : res) {
    std::cout << i << "\t";
  }
  std::cout << std::endl;
  return 0;
}
