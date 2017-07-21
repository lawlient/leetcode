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
  void help(std::vector<std::vector<int>> &res, std::vector<int> &subset, 
            const std::vector<int> &nums, int i, int n, int k) {
    if (subset.size() == k) {
      res.push_back(subset);
      return;
    }
    for (; i < n; i++) {
      subset.push_back(nums[i]);
      help(res, subset, nums, i+1, n, k);
      subset.pop_back();
    }
  }
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<int> subset;
    std::vector<std::vector<int>> res{subset};
    int size = nums.size();
    if (size == 0) return res;
    for (int k = 1; k <= size; k++) {
      help(res, subset, nums, 0, size, k);
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
