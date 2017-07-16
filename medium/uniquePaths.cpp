/*  A robot is located at the top-left corner of a m x n grid.
 *  The robot can only move either down or right at any point in time.
 *  The robot is trying to reach the bottom-right corner of the grid.
 *  How many possible unique paths are there?
 *  
 *  Note: m and n will be at most 100.
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) return 1;
    m--; n--;
    if (m > n) std::swap(m, n);
    int i = 1;
    unsigned p1 = 1;
    long long p2 = n+1;
    while (i < m) {
      p1 *= ++i;
      p2 *= i+n;
    }
    return p2 / p1;
  }
};

int main() {
  Solution solute;
  auto res = solute.uniquePaths(10, 10);
  std::cout << res << "\n";
  return 0;
}
