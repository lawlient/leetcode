/*  Given a binary tree
 *
 *  struct TreeLinkNode {
 *    TreeLinkNode *left;
 *    TreeLinkNode *right;
 *    TreeLinkNode *next;
 *  }
 *  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *  Initially, all next pointers are set to NULL.
 *  Note:
 *
 *  You may only use constant extra space.
 *  You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *  
 *  For example,
 *  Given the following perfect binary tree,
 *
 *        1
 *       /  \
 *      2    3
 *     / \  / \
 *    4  5  6  7
 *  
 *  After calling your function, the tree should look like:
 *
 *       1 -> NULL
 *     /  \
 *    2 -> 3 -> NULL
 *   / \  / \
 *  4->5->6->7 -> NULL
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

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dynamic programming
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    auto pre = root;
    auto cur = pre;
    while (pre->left) {
      cur = pre;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) cur->right->next = cur->next->left;
        cur = cur->next;
      }
      pre = pre->left;
    }
  }
};

int main() {
  Solution solute;
  auto input = new TreeLinkNode(3);
  solute.connect(input);
  // std::cout << res << "\n";
  return 0;
}
