/*  Reverse digits of an integer.
 *  Example1: x = 123, return 321
 *  Example2: x = -123, return -321
 *
 *  Note:
 *    The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <vector>

int reverse(int x) {
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

int main() { 
  srand((unsigned)time(NULL)); 
  int x = rand();
  int x0 = reverse(x);
  std::cout << "x = " << x << std::endl
            << "x0 = " << x0 << std::endl;
  return 0;
}
