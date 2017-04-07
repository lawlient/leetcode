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
    if (!x) return x;
    int l = 1, r = INT_MAX;
    while (true) {
      int mid = l + (r - l) / 2;
      if (mid > x / mid) 
        r = mid - 1;
      else {
        if ((mid + 1) > x / (mid + 1))
          return mid;
        l = mid + 1;
      }
    }
  }
};

int main() {
  std::vector<int> input{9, 9, 9, 9, 9};
  Solution solute;
  auto res = solute.mySqrt(8);
  std::cout << res << std::endl;
  return 0;
}
