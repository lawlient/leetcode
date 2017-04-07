/*  Given an array of integers, every element appears twice except for one. Find that single one.
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
  // my solution
  int singleNumber(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n) {
      if (i+1 < n && nums[i] == nums[i+1])
        i += 2;
      else
        break;
    }
    return nums[i];
  }
  
  // others : XOR operation
  int singleNumber2(std::vector<int> &nums) {
    int res = 0;
    for (const auto &i : nums) 
      res ^= i;
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 3, 3, 1};
  auto res = solute.singleNumber2(input);
  std::cout << res << std::endl;
  return 0;
}
