/*  Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *  For example, given the following triangle
 *  [
 *       [2],
 *      [3,4],
 *     [6,5,7],
 *    [4,1,8,3]
 *  ]
 *
 *  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *  Note:
 *  Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
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
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dynamic programming
class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    for (int i = 1; i <triangle.size(); i++) {
      auto &tmp = triangle[i-1];
      for (int j = 1; j < i; j++) {
        triangle[i][j] += std::min(tmp[j-1], tmp[j]);
      }
      triangle[i][0] = triangle[i][0] + tmp[0];
      triangle[i][i] = triangle[i].back() + tmp.back();
    }
    return *std::min_element(triangle.back().begin(), triangle.back().end());
  }

  // calculate from bottom to top
  int minimumTotal2(std::vector<std::vector<int>> &triangle) {
    std::vector<int> minLen(triangle.back());
    for (int layer = triangle.size() - 2; layer >= 0; layer--)
      for (int i = 0; i <= layer; i++)
        minLen[i] = std::min(minLen[i], minLen[i+1]) + triangle[layer][i];
    return minLen[0];
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<int>> input{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  auto res = solute.minimumTotal(input);
  std::cout << res << "\n";
  return 0;
}
