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

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> res;
    if (nums.size() == 0) return res;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); ++i) {
      int r1 = target - nums[i];
      for (size_t j = i + 1; j < nums.size(); ++j) {
        size_t front = j + 1, back = nums.size() - 1;
        int remain = r1 - nums[j];
        while (front < back) {
          if (nums[front] + nums[back] < remain) front++;
          else if (nums[front] + nums[back] > remain) back--;
          else {
            std::vector<int> one(4, 0);
            one[0] = nums[i];
            one[1] = nums[j];
            one[2] = nums[front];
            one[3] = nums[back];
            res.push_back(one);
            while (front < back && nums[front] == one[2]) front++;
            while (front < back && nums[back] == one[3]) back--;
          }
        }
        while (j < nums.size() - 1 && nums[j] == nums[j+1]) j++;
      }
      while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
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
