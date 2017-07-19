/*  Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.  
 *  You may assume the integer do not contain any leading zero, except the number 0 itself.  
 *  The digits are stored such that the most significant digit is at the head of the list.
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

class Solution {
  std::vector<int> plusOne(std::vector<int> &digits) {
    int c = 1;
    for (int i = digits.size()-1; i >= 0 && c; i--) {
      digits[i] += c;
      c = digits[i] / 10;
      digits[i] %= 10;
    }
    if (c) digits.insert(digits.begin(), c);
    return digits;
  }
};

int main() {
  return 0;
}
