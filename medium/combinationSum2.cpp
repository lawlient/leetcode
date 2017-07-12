/*  Given a collection of candidate numbers (C) and a target number (T),
 *  find all unique combinations in C where the candidate numbers sums to T.
 *  Each number in C may only be used once in the combination.
 *  
 *  Note:
 *    All numbers (including target) will be positive integers.
 *    The solution set must not contain duplicate combinations.
 *
 *  For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 *  A solution set is:
 *  [
 *    [1, 7],
 *    [1, 2, 5],
 *    [2, 6],
 *    [1, 1, 6]
 *  ]
   
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

class Solution {
  void recursiveCombinate(std::vector<std::vector<int>> &res, int begin, int target, 
                          std::vector<int> &r, const std::vector<int> &candidates) {
    if (target == 0) {
      res.push_back(r);
      return;
    }
    for (int i = begin; i < candidates.size(); i++) {
      if (candidates[i] > target) return;
      if (i > begin && candidates[i] == candidates[i-1]) continue;
      r.push_back(candidates[i]);
      recursiveCombinate(res, i+1, target-candidates[i], r, candidates);
      r.pop_back();
    }
  }
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> r;
    recursiveCombinate(res, 0, target, r, candidates);
    return res;
  }
};

int main() {
  return 0;
}
