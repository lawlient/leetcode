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
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int min = nums[0] + nums[1] + nums[2], size = nums.size();
    for (int i = 0; i < size; i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == target) return target;
        sum < target ? l++ : r--;
        if (std::abs((long)target - min) > std::abs((long)target - sum))
          min = sum;
      }
      while (i+1 < size && nums[i] == nums[i+1]) i++;
    }
    return min;
  }
};

int main() {
  Solution solute;
  std::vector<int> a{-1, 2, 1, -4};
  auto res = solute.threeSumClosest(a, 1);
  std::cout << res << std::endl;
  return 0;
}
