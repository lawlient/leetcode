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

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
  void findCombination(std::vector<std::vector<int>> &res, const int order, const int target,
                       std::vector<int> &local, const std::vector<int> &num) {
    if (!target) {
      res.push_back(local);
      return;
    }
    for (size_t i = order; i < num.size(); ++i) {
      if (num[i] > target) return ;
      if (i > order && num[i] == num[i-1]) continue;
      local.push_back(num[i]);
      findCombination(res, i+1, target-num[i], local, num);
      local.pop_back();
    }
 }
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> local;
    findCombination(res, 0, target, local, candidates);
    return res;
  }
};

int main() {
  return 0;
}
