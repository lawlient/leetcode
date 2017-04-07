/*  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 *  Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {

public:
  int threeSum(std::vector<int>& nums, int target) {
    std::stable_sort(nums.begin(), nums.end());
    int min = nums[0] + nums[1] + nums[2];
    for (size_t i = 0; i < nums.size(); ++i) {
      size_t front = i + 1;
      size_t back = nums.size() - 1;
      
      while (front < back) {
        int sum = nums[i] + nums[front] + nums[back];

        if (sum < target) {
          if (std::abs(min - target) > target - sum) {
            min = sum;
          }
          front++;
        }
        else if (sum > target) {
          if (std::abs(min - target) > sum - target) {
            min = sum;
          }
          back--;
        }
        else {
          return target;
        }
      }
      while (i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
    }
    return min;
  }
};

int main() {
  Solution solute;
  std::vector<int> a{-1, 2, 1, -4};
  auto res = solute.threeSum(a, 1);
  std::cout << res << std::endl;
  return 0;
}
