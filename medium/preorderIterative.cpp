/*  Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 *  For example:
 *  Given binary tree {1,#,2,3},
 *  
 *     1
 *      \
 *       2
 *      /
 *     3
 *  
 *  return [1,2,3].
 *  
 *  Note: Recursive solution is trivial, could you do it iteratively?
 *
*/

/*  stack s reserve every right node
 *  s.top is the nearest right node
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    while (root) {
      res.push_back(root->val);
      if (root->right) s.push(root->right);
      root = root->left;
      if (root == nullptr && !s.empty()) {
        root = s.top();
        s.pop();
      }
    }
    return res;
  }

  std::vector<int> preorderTraversal2(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    while (root || !s.empty()) {
      if (root) {
        res.push_back(root->val);
        s.push(root);
        root = root->left;
        continue;
      }
      root = s.top()->right;
      s.pop();
    }
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode head(1);
  auto res = solute.preorderTraversal(&head);
  for (auto i : res) {
    std::cout << i << "\t";
  }
  std::cout << std::endl;
  return 0;
}
