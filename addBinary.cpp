/*  Given two binary strings, return their sum (also a binary string).
 *
 *  For example,
 *  a = "11"
 *  b = "1"
 *  Return "100". 
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int i = a.size()-1, j = b.size()-1;
    int c = 0;
    std::string res("");
    while (i >= 0 || j >= 0 || c == 1) {
      c += i >= 0 ? a[i--] - '0' : 0;
      c += j >= 0 ? b[j--] - '0' : 0;
      res = static_cast<char>(c%2 + '0') + res;
      c /= 2;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::string a("11");
  std::string b("1");
  auto res = solute.addBinary(a, b);
  std::cout << res << std::endl;
  return 0;
}
