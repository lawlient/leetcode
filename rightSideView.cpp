/*  Given a binary tree, imagine yourself standing on the right side of it,
 *  return the values of the nodes you can see ordered from top to bottom.  
 *
 *  For example:
 *    Given the following binary tree,
 *    
 *       1            <---
 *     /   \
 *    2     3         <---
 *     \     \
 *      5     4       <---
 *    
 *    You should return [1, 3, 4]. 
 *
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
#include <set>
#include <queue>
#include <string>
#include <list>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> res;
    if (root == nullptr) return res;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto size = queue.size();
      TreeNode *node = nullptr;
      for (unsigned i = 0; i < size; i++) {
        node = queue.front();
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
        queue.pop();
      }
      res.push_back(node->val);
    }
    return res;
  }
};
