/*  Divide two integers without using multiplication, division and mod operator.
 *  If it is overflow, return MAX_INT.
 *
*/

/*  bit operator
 *  
 *  
 *  
*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <list>

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    if (dividend == 0) return 0;
    bool unsign = ((dividend > 0) && (divisor > 0)) ||
                  ((dividend < 0) && (divisor < 0));
    long long m = std::abs((long long)dividend);
    long long n = std::abs((long long)divisor);
    unsigned r = 0;
    while (n <= m) {
      auto d = n;
      long long c = 1;
      while ((d << 1) < m) {
        c <<= 1;
        d <<= 1;
      }
      r += c;
      m -= d;
    }
    return unsign ? r : -r;
  }
};

int main() {
  std::cout << Solution().divide(10, 3) << std::endl;
  std::cout << Solution().divide(9, 2) << std::endl;
  return 0;
}
