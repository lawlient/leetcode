/*  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 *  For example,
 *  If n = 4 and k = 2, a solution is:
 *  [
 *    [2,4],
 *    [3,4],
 *    [2,3],
 *    [1,2],
 *    [1,3],
 *    [1,4],
 *  ]
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
  void combineRecursive(std::vector<std::vector<int>> &res, std::vector<int> &one, int i, int n, int k) {
    if (one.size() == k) {
      res.push_back(one);
      return;
    }
    for (; i <= n; i++) {
      one.push_back(i);
      combineRecursive(res, one, i + 1, n, k);
      one.pop_back();
    }
  }
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> one;
    combineRecursive(res, one, 1, n, k);
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.combine(4, 2);
  for (const auto &s : res) {
    for (const auto &i : s) {
      std::cout << i << "\t";
    }
    std::cout << "\n";
  }

  return 0;
}
