/*  Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 *  Note: The solution set must not contain duplicate subsets.
 *  
 *  For example,
 *  If nums = [1,2,2], a solution is:
 *  [
 *    [2],
 *    [1],
 *    [1,2,2],
 *    [2,2],
 *    [1,2],
 *    []
 *  ]
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res({{}});
    for (int i = 0; i < nums.size();) {
      int count = 0;
      while (count + i < nums.size() && nums[i + count] == nums[i]) count++;
      int prevN = res.size();
      for (int j = 0; j < prevN; j++) {
        std::vector<int> one = res[j];
        for (int k = 1; k <= count; k++) {
          one.push_back(nums[i]);
          res.push_back(one);
        }
      }
      i += count;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 2};
  std::vector<int> input2{1};
  auto res = solute.subsetsWithDup(input);
  for (auto a : res) {
    for (auto i : a) {
      std::cout << i << "\t";
    }
    std::cout << "\n";
  }
  return 0;
}
