/*  Two elements of a binary search tree (BST) are swapped by mistake.
 *  Recover the tree without changing its structure.
 *  Note:
 *  A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
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
  TreeNode *firstNode = NULL;
  TreeNode *secondNode = NULL;
  TreeNode *prevNode = new TreeNode(INT_MIN);

  void traverse(TreeNode *root) {
    if (!root) return;
    traverse(root->left);

    if (!firstNode && root->val <= prevNode->val)
      firstNode = prevNode;

    if (firstNode && root->val <= prevNode->val)
      secondNode = root;

    prevNode = root;
    traverse(root->right);
  }
public:
  void recover(TreeNode *root) {
    traverse(root);

    std::swap(firstNode->val, secondNode->val);
  }
};

int main() {
  Solution solute;
  TreeNode node1(0);
  solute.recover(&node1);
  // std::cout << res << "\n";
  return 0;
}
