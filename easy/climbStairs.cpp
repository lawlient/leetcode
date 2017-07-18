/*  You are climbing a stair case. It takes n steps to reach to the top.
 *  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *  Note: Given n will be a positive integer. 
 *  
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


// f(n) = f(n-1) + f(n-2)
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 3) return n;
    int i = 2, j = 3;
    n = n - 3;
    while (n--) {
      j = i + j;
      i = j - i;
    }
    return j;
  }
};

int main() {
  std::vector<int> input{9, 9, 9, 9, 9};
  Solution solute;
  auto res = solute.climbStairs(7);
  std::cout << res << std::endl;
  return 0;
}
