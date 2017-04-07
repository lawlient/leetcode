/*  Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 *  Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
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
#include <queue>
#include <math.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int ones = 0, twos = 0;
    for (const auto &i : nums) {
      ones = (ones ^ i) & ~twos;
      twos = (twos ^ i) & ~ones;
      std::cout << "ones = " << ones << "\t"
                << "twos = " << twos << std::endl;
    }
    return ones;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 1, 3, 2, 3, 3, 1};
  auto res = solute.singleNumber(input);
  std::cout << res << std::endl;
  return 0;
}
