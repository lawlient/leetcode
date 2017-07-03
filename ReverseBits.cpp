/*  Reverse bits of a given 32 bits unsigned integer.  
 *  For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 *  return 964176192 (represented in binary as 00111001011110000010100101000000).  
 *
 *  Follow up:
 *    If this function is called many times, how would you optimize it?  
 *    Related problem: Reverse Integer
 *
 *
*/

/*  
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
  // same as merge sort
  uint32_t reverseBits1(uint32_t n) {
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = (n >> 16) | (n << 16);
    return n;
  }

  
  uint32_t reverseBits2(uint32_t n) {
    uint32_t m = 0;
    for (int i = 0; i < 32; i++) {
      m <<= 1;
      m |= n & 1;
      n >>= 1;
    }
    return m;
  }
};

int main() {
  std::cout << Solution().reverseBits1(43261596) << std::endl;
  std::cout << Solution().reverseBits2(43261596) << std::endl;
  return 0;
}
