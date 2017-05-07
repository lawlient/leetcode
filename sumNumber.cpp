/*  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *  An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *  Find the total sum of all root-to-leaf numbers.
 *  
 *  For example,
 *
 *      1
 *     / \
 *    2   3
 *  
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *  Return the sum = 12 + 13 = 25. 
 *  
 *
 *
*/

/*  depth first search
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
  int visit(TreeNode *root, int res) {
    if (!root) return 0;

    res = res * 10 + root->val;
    if (!root->left && !root->right)
      return res;

    return visit(root->left, res) + visit(root->right, res);
  }
public:
  int sumNumbers(TreeNode *root) {
    return visit(root, 0);
  }

  // not recursively
  int sumNumbers2(TreeNode *root) {
    int res = 0;
    if (!root) return res;
    std::stack<TreeNode *> s;
    s.push(root);
    int p = s.top()->val;
    while (!s.empty()) {
      auto t = s.top();
      if (!t->left && !t->right) {
        res += p;
        s.pop();
        p /= 10;
        while (!s.empty() && ((s.top()->right == t) ||
               (s.top()->left == t && s.top()->right == NULL))) {
          t = s.top();
          s.pop();
          p /= 10;
        }
        if (!s.empty() && s.top()->right) {
          p = p * 10 + s.top()->right->val;
          s.push(s.top()->right);
        }
        continue;
      }
      if (t->left) {
        s.push(t->left);
        p = p * 10 + t->left->val;
        continue;
      }
      if (t->right) {
        s.push(t->right);
        p = p * 10 + t->right->val;
        continue;
      }
    }
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(3);
  node1.left  = &node2;
  node1.right  = &node3;
  auto res = solute.sumNumbers(&node1);
  std::cout << res << std::endl;
  return 0;
}
