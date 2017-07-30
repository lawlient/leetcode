/*  Say you have an array for which the ith element is the price of a given stock on day i.  
 *  Design an algorithm to find the maximum profit. You may complete at most two transactions.  
 *
 *  Note:
 *  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *  
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
#include <queue>

class Solution {
  int help(std::vector<int> &prices, int b, int e) {
    if (b >= e) return 0;
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = b; i <= e; i++) {
      minPrice = std::min(minPrice, prices[i]);
      maxPro = std::max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
  }
public:
  int maxProfit(std::vector<int> &prices) {
    int maxPro = 0;
    int maxLeft = 0, maxRight = 0;
    int b = 0, e = prices.size()-1;
    for (; b <= e; b++)
      if (prices[b] < prices[b+1])
        break;

    for (; e >= b; e--)
      if (prices[e] > prices[e-1])
        break;

    for (int i = b; i <= e; i++) {
      maxLeft = help(prices, 0, i);
      maxRight = help(prices, i+1, prices.size()-1);
      maxPro = std::max(maxPro, maxLeft + maxRight);
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
