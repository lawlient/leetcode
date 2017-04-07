/*  Say you have an array for which the ith element is the price of a given stock on day i.
 *  If you were only permitted to complete at most one transaction
 *  (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *  Example 1:
 *  Input: [7, 1, 5, 3, 6, 4]
 *  Output: 5
 *
 *  max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 *  Example 2:
 *  Input: [7, 6, 4, 3, 1]
 *  Output: 0
 *  In this case, no transaction is done, i.e. max profit = 0.
 *
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int minPrice = INT_MAX;
    int maxPro = 0;
    for (size_t i = 0; i < prices.size(); i++) {
      minPrice = std::min(minPrice, prices[i]);
      maxPro = std::max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{7, 1, 5, 3, 6, 4};
  auto res = solute.maxProfit(input);
  std::cout << res << "\n";
  return 0;
}
