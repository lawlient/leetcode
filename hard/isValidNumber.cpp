/*  Validate if a given string is numeric.
 *  Some examples:
 *  "0" => true
 *  " 0.1 " => true
 *  "abc" => false
 *  "1 a" => false
 *  "2e10" => true
 *
 *  Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  bool isNumber(std::string s) {
    size_t i = s.find_first_not_of(' ', 0), n = s.size();
    if (i < n && (s[i] == '+' || s[i] == '-')) i++;
    int pointNumber = 0, digitNumber = 0;
    while (i < n && (s[i] == '.' || std::isdigit(s[i])))
        s[i++] == '.' ? pointNumber++ : digitNumber++;

    if (pointNumber > 1 || digitNumber < 1) return false;
    if (i < n && s[i] == 'e') {
      i++;
      if (i < n && (s[i] == '+' || s[i] == '-')) i++;
      auto copy = i;
      while (i < n && std::isdigit(s[i]))
        ++i;
      if (copy == i) return false;
    }
    while (i < n && s[i] == ' ') i++;
    return i == n;
  }

  bool isNumber2(std::string s) {
    size_t i = s.find_first_not_of(' ', 0), n = s.size();
    int pointNumber = 0, digitNumber = 0;
    if (i < n && (s[i] == '+' || s[i] == '-')) i++;
    while (i < n && (s[i] == '.' || std::isdigit(s[i])))
        s[i++] == '.' ? pointNumber++ : digitNumber++;

    if (pointNumber > 1 || digitNumber < 1) return false;
    if (i < n && s[i] == 'e') {
      i++;
      if (i < n && (s[i] == '+' || s[i] == '-')) i++;
      int digitN = 0;
      while (i < n && std::isdigit(s[i])) {
        ++i;
        digitN++;
      }
      if (digitN < 1) return false;
    }
    while (i < n && s[i] == ' ') i++;
    return i == n;
  }
};

int main() {
  Solution solute;
  std::string s("1 a");
  auto res = solute.isNumber(s);
  std::cout << res << std::endl;
  return 0;
}
