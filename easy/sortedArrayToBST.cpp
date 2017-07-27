/*  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
  TreeNode *buildTree(std::vector<int> &nums, int b, int e) {
    if (b > e) return NULL;
    int r = b + (e - b) / 2;
    auto root = new TreeNode(nums[r]);
    root->left = buildTree(nums, b, r-1);
    root->right = buildTree(nums, r+1, e);
    return root;
  }
public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return buildTree(nums, 0, nums.size()-1);
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 3, 5, 6};
  auto res = solute.sortedArrayToBST(input);
  std::cout << res->val << "\n";
  return 0;
}
