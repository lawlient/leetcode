/*  Implement pow(x, n).
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  double myPow(double x, int n) {
    unsigned long long p = n;
    if (n < 0) {
      p = -n;
      x = 1/x;
    }
    double ans = 1;
    while (p) {
      if (p & 1) ans *= x;
      x *= x;
      p >>= 1;
    }
    return ans;
  }
};

int main() {
  Solution solute;
  auto res = solute.myPow(3.2, 3);
  std::cout << res << "\t";
  return 0;
}
