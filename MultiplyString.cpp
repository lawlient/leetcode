/*  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 *
 *  Note:
 *    The length of both num1 and num2 is < 110.
 *    Both num1 and num2 contains only digits 0-9.
 *    Both num1 and num2 does not contain any leading zero.
 *    You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int l1 = num1.size(), l2 = num2.size();
    std::vector<int> reverse(l1 + l2, 0);
    for (int i = 0; i < l1; ++i) {
      int c = 0;
      int n1 = static_cast<int>(num1[l1 - i - 1] - '0');
      for (int j = 0; j < l2; ++j) {
        int sum = n1 * static_cast<int>(num2[l2 - j - 1] - '0') + reverse[i+j] + c;
        c = sum / 10;
        reverse[i+j] = sum % 10;
      }
      reverse[i+l2] += c;
    }
    std::string r_res = "";
    for (auto i : reverse) {
      r_res += i + '0';
    }
    std::string res;
    auto begin = r_res.begin();
    std::reverse_copy(begin, begin+r_res.find_last_not_of('0')+1, std::back_inserter(res));
    return res;
  }
};

int main() {
  std::string n1 = "98", n2 = "9";
  Solution solute;
  std::cout << solute.multiply(n1, n2) << std::endl;
  
  return 0;
}
