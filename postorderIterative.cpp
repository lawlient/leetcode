/*  Given a binary tree, return the postorder traversal of its nodes' values.
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
 *  return [3,2,1].
 *  
 *  Note: Recursive solution is trivial, could you do it iteratively?
 *
*/

/*  
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
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    if (!root) return res;
    s.push(root);
    while (!s.empty()) {
      auto t = s.top();
      s.pop();
      res.push_back(t->val);
      if (t->left) s.push(t->left);
      if (t->right) s.push(t->right);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode head(1);
  auto res = solute.postorderTraversal(&head);
  for (auto i : res) {
    std::cout << i << "\t";
  }
  std::cout << std::endl;
  return 0;
}
