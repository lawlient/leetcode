/*  Given a collection of distinct numbers, return all possible permutations.
 *
 *  For example,
 *    [1,2,3] have the following permutations:
 *
 *    [
 *      [1,2,3],
 *      [1,3,2],
 *      [2,1,3],
 *      [2,3,1],
 *      [3,1,2],
 *      [3,2,1]
 *    ]
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
  void permutationRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result) {
    if (begin == static_cast<int>(nums.size())) {
      result.push_back(nums);
      return;
    }

    for (int i = begin; i < static_cast<int>(nums.size()); ++i) {
      std::swap(nums[begin], nums[i]);
      permutationRecursive(nums, begin+1, result);
      std::swap(nums[i], nums[begin]);
    }
  }
public:
  std::vector<std::vector<int>> permutation(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    permutationRecursive(nums, 0, result);
    return result;
  }
};

int main() {
  std::vector<int> nums{1, 2, 3};
  Solution solute;
  auto res = solute.permutation(nums);
  for (auto i : res) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
