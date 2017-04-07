/*  Follow up for problem "Populating Next Right Pointers in Each Node".
 *  What if the given tree could be any binary tree? Would your previous solution still work?
 *  Note:
 *      You may only use constant extra space.
 *  For example,
 *  Given the following binary tree,
 *
 *        1
 *      /  \
 *     2    3
 *    / \    \
 *   4   5    7
 *
 *  After calling your function, the tree should look like:
 *
 *       1 -> NULL
 *     /  \
 *    2 -> 3 -> NULL
 *   / \    \
 *  4-> 5 -> 7 -> NULL
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

class Solution {
public:
  void connect(TreeLinkNode *root) {
    while (root) {
      auto tmp = new TreeLinkNode(0);
      auto cur = tmp;
      while (root) {
        if (root->left) cur = cur->next = root->left;
        if (root->right) cur = cur->next = root->right;
        root = root->next;
      }
      root = tmp->next;
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
