/*  Given numRows, generate the first numRows of Pascal's triangle.
 *  For example, given numRows = 5,
 *  Return
 *  [
 *        [1],
 *       [1,1],
 *      [1,2,1],
 *     [1,3,3,1],
 *    [1,4,6,4,1]
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
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    if (numRows == 0) return res;
    res.push_back(std::vector<int>(1, 1));
    for (int i = 1; i < numRows; i++) {
      std::vector<int> line(i+1, 1);
      auto &lastLine = res.back();
      for (int j = 1; j < i; j++) {
        line[j] = lastLine[j-1] + lastLine[j];
      }
      res.push_back(line);
    }
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.generate(7);
  for (auto l : res) {
    for (auto i : l) 
      std::cout << i << "\t";
    std::cout << std::endl;
  }
  return 0;
}
