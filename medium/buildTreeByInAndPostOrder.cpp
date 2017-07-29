/*  Given inorder and postorder traversal of a tree, construct the binary tree.
 *  Note:
 *  You may assume that duplicates do not exist in the tree. 
 *  
 * 
*/


/*  non-recursive
 *  1. create root
 *  2. create right child first
 *  3. create left child inverted order
 *  so we need a stack to record right node
 *
 *
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <stack>
#include <queue>
#include <math.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  std::map<int, int> postIndex;
  TreeNode *buildTreeRec(std::vector<int> &inorder,int ib, int ie,
                         std::vector<int> &postorder, int pb, int pe) {
    if (ib > ie || pb > pe) return NULL;
    auto node = new TreeNode(postorder[pe]);
    int pos = postIndex[postorder[pe]];
    node->left = buildTreeRec(inorder, ib, pos-1, postorder, pb, pb + pos - ib - 1);
    node->right = buildTreeRec(inorder, pos+1, ie, postorder, pb + pos - ib, pe-1);
    return node;
  }
public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    if (inorder.empty()) return NULL;
    for (size_t i = 0; i < postorder.size(); i++)
      postIndex[inorder[i]] = i;
    return buildTreeRec(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
  }

  TreeNode *buildTree2(std::vector<int> &inorder, std::vector<int> &postorder) {
    if (postorder.empty()) return nullptr;
    auto root = new TreeNode(postorder.back());
    std::stack<TreeNode *> s; s.push(root);
    int i = postorder.size() - 2;
    int j = inorder.size() - 1;
    auto t = root;
    bool rightInsert = true;
    while (i >= 0) {
      if (!s.empty() && s.top()->val == inorder[j]) {
        t = s.top(); s.pop();
        rightInsert = false;
        j--;
      } else {
        if (rightInsert) {
          t = t->right = new TreeNode(postorder[i]);
        } else {
          t = t->left = new TreeNode(postorder[i]);
          rightInsert = true;
        }
        s.push(t);
        i--;
      }
    }
    return root;
  }
};

int main() {
  Solution solute;
  std::vector<int> inorder{1, 2}, postorder{2, 1};
  auto res = solute.buildTree(inorder, postorder);
  std::cout << res->val << std::endl;
  std::cout << "left is " << (res->left ? 1 : 0) << std::endl;
  std::cout << "right is " << (res->right ? 1 : 0) << std::endl;
  return 0;
}
