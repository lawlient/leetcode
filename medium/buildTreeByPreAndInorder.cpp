/*  Given preorder and inorder traversal of a tree, construct the binary tree.
 *  Note:
 *  You may assume that duplicates do not exist in the tree. 
 *  
 *  
*/


/*  we create tree by preorder
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
    int i = 1; // index in preorder
    int j = 0; // index in inorder
    bool leftInsert = true; // insert in left or right
    std::stack<TreeNode *> st; st.push(root); // record tree node
    auto t = root;
    while (i < preorder.size()) {
      if (!st.empty() && (st.top()->val == inorder[j])) {
      // left tree and root done,next should create right tree
        t = st.top(); st.pop();
        leftInsert = false;
        j++;
      } else {
        if (leftInsert) {
          t = t->left = new TreeNode(preorder[i]);
        } else {
          t = t->right = new TreeNode(preorder[i]);
          leftInsert = true;
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
