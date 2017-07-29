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
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// dynamic programming
class Solution {
public:
  void connect(TreeLinkNode *root) {
    std::queue<TreeLinkNode *> s;
    if (root) s.push(root);
    while (!s.empty()) {
      int size = s.size();
      for (int i = 0; i < size; i++) {
        auto node = s.front(); s.pop();
        if (i < size - 1) node->next = s.front();
        if (node->left) s.push(node->left);
        if (node->right) s.push(node->right);
      }
    }
  }

  // constant extra space
  void connect2(TreeLinkNode *root) {
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
