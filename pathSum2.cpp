/*  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *  For example:
 *  Given the below binary tree and sum = 22,
 * 
 *  
 *            5
 *           / \
 *          4   8
 *         /   / \
 *        11  13  4
 *       /  \    / \
 *      7    2  5   1
 *
 *  return
 *  [
 *    [5,4,11,2],
 *    [5,8,4,5]
 *  ]
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  void solveRec(std::vector<std::vector<int>> &res, std::vector<int> &solve, TreeNode *root, int sum) {
    solve.push_back(root->val);
    if (!root->left && !root->right)
      if (root->val == sum)
        res.push_back(solve);

    if (root->left) solveRec(res, solve, root->left, sum-root->val);
    if (root->right) solveRec(res, solve, root->right, sum-root->val);
    solve.pop_back();
  }
public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int>> res;
    if (!root) return res;
    std::vector<int> solve;
    solveRec(res, solve, root, sum);
    return res;
  }
};

int main() {
  Solution solute;
  TreeNode *root = new TreeNode(3);
  auto res = solute.pathSum(root, 3);
  for (auto one : res) {
    for (auto i : one) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
