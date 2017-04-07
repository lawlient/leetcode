/*  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *  For example,
 *    [1,1,2] have the following unique permutations:
 *
 *    [
 *      [1,1,2],
 *      [1,2,1],
 *      [2,1,1]
 *    ]
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
  void permutationRecursive(std::vector<int> nums, int begin, std::vector<std::vector<int>> &result) {
    if (begin >= static_cast<int>(nums.size()) - 1) {
      result.push_back(nums);
      return;
    }

    for (int i = begin; i < static_cast<int>(nums.size()); ++i) {
      if (i != begin && nums[begin] == nums[i]) continue;
      std::swap(nums[begin], nums[i]);
      permutationRecursive(nums, begin+1, result);
    }
  }
public:
  std::vector<std::vector<int>> permutation(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    permutationRecursive(nums, 0, result);
    return result;
  }
};

int main() {
  std::vector<int> nums{1, 1, 3};
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
