/*  Reverse digits of an integer.
 *  Example1: x = 123, return 321
 *  Example2: x = -123, return -321
 *
 *  Note:
 *    The input is assumed to be a 32-bit signed integer.
 *    Your function should return 0 when the reversed integer overflows. 
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <ctime>
#include <vector>

class Solution {
public:
  int reverse(int x) {
    long res = 0;
    while (x) {
      res = res * 10 + x % 10;
      x = x / 10;
      if (res < INT_MIN || res > INT_MAX)
        return 0;
    }
    return res;
  }

  int reverse2(int x) {
    std::string s = std::to_string(x > 0 ? x : -x);
    std::reverse(s.begin(), s.end());
    int ret = 0;
    try {
      ret = std::stoi(s);
    } catch (const std::out_of_range &err) {
      return 0;
    }
    if (x < 0) {
      ret = -ret;
    }
    return ret;
  }
};


int main() {
  std::cout << Solution().reverse(-123) << std::endl;
  return 0;
}
