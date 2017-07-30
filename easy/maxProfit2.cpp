/*  Say you have an array for which the ith element is the price of a given stock on day i.  
 *  Design an algorithm to find the maximum profit. 
 *  You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
 *  However, you may not engage in multiple transactions at the same time 
 *  (ie, you must sell the stock before you buy again).
 *  
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
public:
  int maxProfit(std::vector<int> &prices) {
    int minPrice = INT_MAX;
    int maxPro = 0;
    int max = 0;
    prices.push_back(0);
    for (size_t i = 0; i < prices.size() - 1; i++) {
      minPrice = std::min(minPrice, prices[i]);
      maxPro = std::max(maxPro, prices[i] - minPrice);
      if (prices[i] >= prices[i+1]) {
        max += maxPro;
        minPrice = prices[i+1];
        maxPro = 0;
        continue;
      }
    }
    return max;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{7, 1, 5, 3, 6, 4};
  auto res = solute.maxProfit(input);
  std::cout << res << "\n";
  return 0;
}
