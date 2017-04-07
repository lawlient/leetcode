/*  Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 *  For example,
 *  Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
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
  std::vector<TreeNode *> generateRecursive(int start, int end) {
    std::vector<TreeNode *> res;
    if (start > end) {
      res.push_back(NULL);
      return res;
    }
    if (start == end) {
      res.push_back(new TreeNode(start));
      return res;
    }
    std::vector<TreeNode *> left, right;
    for (int i = start; i <= end; i++) {
      left = generateRecursive(start, i-1);
      right = generateRecursive(i+1, end);
      for (auto l : left) {
        for (auto r : right) {
          TreeNode *root = new TreeNode(i);
          root->left = l;
          root->right = r;
          res.push_back(root);
        }
      }
    }

    return res;
  }
public:
  std::vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return std::vector<TreeNode *>();
    return generateRecursive(1, n);
  }
};

int main() {
  Solution solute;
  auto res = solute.generateTrees(0);
  std::cout << res.size() << "\t";
  return 0;
}
