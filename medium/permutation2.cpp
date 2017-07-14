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
  void help(std::vector<std::vector<int>> &res, int begin, std::vector<int> nums) {
    if (begin == nums.size() - 1) {
      res.push_back(nums);
      return;
    }
    help(res, begin+1, nums);
    for (int i = begin+1; i < nums.size(); i++) {
      if(nums[i] == nums[begin]) continue;
      std::swap(nums[i], nums[begin]);
      help(res, begin+1, nums);
    }
  }
public:
  std::vector<std::vector<int>> permutation(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    help(res, 0, nums);
    return res;
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
