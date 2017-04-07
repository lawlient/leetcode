/*  Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 *  find all unique combinations in C where the candidate numbers sums to T.
 *  The same repeated number may be chosen from C unlimited number of times.
 *
 *  Note:
 *    All numbers (including target) will be positive integers.
 *    The solution set must not contain duplicate combinations.
 *
 *  For example, given candidate set [2, 3, 6, 7] and target 7,
 *
 *  A solution set is:
 *  [
 *    [7],
 *    [2, 2, 3]
 *  ]
 *  
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
  void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &res,
                      std::vector<int> &combination, int begin) {
    if (!target) {
      res.push_back(combination);
      return;
    }
    for (size_t i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
      combination.push_back(candidates[i]);
      combinationSum(candidates, target - candidates[i], res, combination, i);
      combination.pop_back();
    }
  }
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
  }
};

int main() {
  return 0;
}
