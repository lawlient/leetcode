/*  Implement int sqrt(int x).
 *  Compute and return the square root of x.
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>


class Solution {
public:
  int mySqrt(int x) {
    assert(x >= 0);
    if (x == 0) return 0;
    int l = 0, r = INT_MAX;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (m > x / m) r = m - 1;
      else {
        l = m + 1;
        if (l > x / l)
          return m;
      }
    }
    return l;
  }
};

int main() {
  std::cout << Solution().mySqrt(2) << std::endl;
  return 0;
}
