/*  Given preorder and inorder traversal of a tree, construct the binary tree.
 *  Note:
 *  You may assume that duplicates do not exist in the tree. 
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
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.empty()) return NULL;
    TreeNode *root = new TreeNode(preorder[0]);
    int i = 1, j = 0;
    bool leftIns = true;
    std::stack<TreeNode *> st; st.push(root);
    auto t = root;
    while (i < preorder.size()) {
      if (!st.empty() && (st.top()->val == inorder[j])) {
        t = st.top(); st.pop();
        leftIns = false;
        j++;
      } else {
        if (leftIns) {
          t = t->left = new TreeNode(preorder[i]);
        } else {
          t = t->right = new TreeNode(preorder[i]);
          leftIns = true;
        }
        st.push(t);
        i++;
      }
    }
    return root;
  }
};

int main() {
  Solution solute;
  // TreeNode node1(1);
  // auto res = solute.buildTree(&node1);
  // std::cout << res << "\n";
  return 0;
}
