/*   Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 *   For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 *   the contiguous subarray [4,-1,2,1] has the largest sum = 6. 
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int ans = nums[0], sum = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      sum += nums[i];
      ans = std::max(ans, sum);
      if (sum < 0) sum = 0;
    }
    return ans;
  }
};

int main() {
  std::vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution solute;
  auto res = solute.maxSubArray(input);
  std::cout << res << std::endl;
  return 0;
}
