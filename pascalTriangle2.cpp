/*   Given an index k, return the kth row of the Pascal's triangle.
 *
 *   For example, given k = 3,
 *   Return [1,3,3,1].
 *
 *   Note:
 *   Could you optimize your algorithm to use only O(k) extra space? 
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

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> res(1, 1);
    for (int i = 1; i < rowIndex+1; i++) {
      std::vector<int> nextL(i+1, 1);
      for (int j = 1; j < i; j++) {
        nextL[j] = res[j-1] + res[j];
      }
      std::swap(res, nextL);
    }
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.getRow(3);
  for (auto i : res) 
    std::cout << i << "\t";
  std::cout << std::endl;
  return 0;
}
