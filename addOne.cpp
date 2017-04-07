/*  Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *  You may assume the integer do not contain any leading zero, except the number 0 itself.
 *  The digits are stored such that the most significant digit is at the head of the list.
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
public:
  std::vector<int> addOne(std::vector<int> &digits) {
    int i;
    for (i = digits.size()-1; i >= 0; i--) {
      if (digits[i] != 9) {
        digits[i] = digits[i] + 1;
        break;
      }
      digits[i] = 0;
    }
    if (i < 0) digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  std::vector<int> input{9, 9, 9, 9, 9};
  Solution solute;
  auto res = solute.addOne(input);
  for (auto r : res) {
    std::cout << r << '\t';
  }
  std::cout << std::endl;
  return 0;
}
