/*  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 *  Find all unique quadruplets in the array which gives the sum of target.
    
    For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
    
    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
*/

/*  see threeSum.cpp
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int r1 = target - nums[i];
      for (int j = i + 1; j < size; j++) {
        int l = j + 1, r = size - 1;
        int r2 = r1 - nums[j];
        while (l < r) {
          int sum = nums[l] + nums[r];
          if (sum == r2) {
            std::vector<int> result{nums[i], nums[j], nums[l], nums[r]};
            res.push_back(result);
            while (l < r && nums[l] == result[2]) l++;
            while (l < r && nums[r] == result[3]) r--;
          } else sum < r2 ? l++ : r--;
        }
        while (j+1 < size && nums[j] == nums[j+1]) j++;
      }
      while (i+1 < size && nums[i] == nums[i+1]) i++;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> nums{1, 0, -1, 0, 2, -2};
  for (auto r : solute.fourSum(nums, 0)) {
    for (auto n : r) {
      std::cout << n << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
