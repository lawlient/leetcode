/*  Given two binary trees, write a function to check if they are equal or not.
 *  Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if ((p && !q) || (!p && q)) return false;
    if (p && q && q->val != p->val) 
      return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  bool isSameTree2(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if ((!p && q) || (p && !q)) return false;
    if (p->val != q->val) return false;
    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
      return true;
    return false;
  }
};

int main() {
  Solution solute;
  TreeNode *p = nullptr, *q = nullptr;
  auto res = solute.isSameTree(p, q);
  std::cout << res << "\n";
  return 0;
}
