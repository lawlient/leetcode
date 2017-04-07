/*  Given a set of distinct integers, nums, return all possible subsets.
 *  Note: The solution set must not contain duplicate subsets.
 *  
 *  For example,
 *    If nums = [1,2,3], a solution is:
 *    [
 *      [3],
 *      [1],
 *      [2],
 *      [1,2,3],
 *      [1,3],
 *      [2,3],
 *      [1,2],
 *      []
 *    ]
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

class Solution {
  void combineRecursive(std::vector<std::vector<int>> &res, std::vector<int> &com,
                        const std::vector<int> &nums, int i, int k) {
    if (com.size() == k) {
      res.push_back(com);
      return;
    }
    for (; i < nums.size(); i++) {
      com.push_back(nums[i]);
      combineRecursive(res, com, nums, i+1, k);
      com.pop_back();
    }
    return;
  }
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> com;
    for (size_t i = 0; i <= nums.size(); i++) {
      combineRecursive(res, com, nums, 0, i);
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 3};
  auto res = solute.subsets(input);
  for (auto s : res) {
    for (auto i : s) {
      std::cout << i << "\t";
    }
    std::cout << "\n";
  }

  return 0;
}
