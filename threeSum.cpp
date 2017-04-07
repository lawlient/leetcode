/*  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 *  Find all unique triplets in the array which gives the sum of zero.
 *
 *  Note: The solution set must not contain duplicate triplets.
 *
 *  For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 *  A solution set is:
 *  [
 *    [-1, 0, 1],
 *    [-1, -1, 2]
 *  ]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {

public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::stable_sort(nums.begin(), nums.end());
    std::cout << std::endl;
    std::vector<std::vector<int>> res;
    for (size_t i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      size_t front = i + 1;
      size_t back = nums.size() - 1;
      
      while (front < back) {
        int sum = nums[front] + nums[back];

        if (sum < target) front++;
        else if (sum > target) back--;
        else {
          std::vector<int> triplet(3, 0);
          triplet[0] = nums[i];
          triplet[1] = nums[front];
          triplet[2] = nums[back];
          res.push_back(triplet);

          while (front < back && nums[front] == triplet[1]) front++;
          while (front < back && nums[back] == triplet[2]) back--;
        }
      }
      while (i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> a{-1, 0, 1, 2, -1, -4};
  auto res = solute.threeSum(a);
  std::cout << res.size() << std::endl;
  for (auto r : res) {
    for (auto i : r) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
