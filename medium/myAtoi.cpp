/*  Implement atoi to convert a string to an integer.
 *
 *  Hint: Carefully consider all possible input cases. If you want a challenge, 
 *        please do not see below and ask yourself what are the possible input cases.
 *        
 *  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 *         You are responsible to gather all the input requirements up front. 
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <climits>

class Solution {
public:
  int myAtoi(std::string str) {
    int i = 0, n = 0, sign = 1;
    while (str[i] == ' ') i++;
    if (str[i] == '-' || str[i] == '+') {
      sign = str[i++] == '-' ? -1 : 1;
    }
    while (i < str.size() && std::isdigit(str[i])) {
      n = n * 10 + (str[i++] - '0');
      if (n * sign >= INT_MAX) return INT_MAX;
      if (n * sign <= INT_MIN) return INT_MIN;
    }
    return n * sign;
  }

  int myAtoi2(std::string str) {
    int ret = 0;
    try {
      ret = std::stoi(str);
    } catch (const std::out_of_range &) {
      return std::string::npos == str.find('-') ? INT_MAX : INT_MIN;
    } catch (const std::invalid_argument &) {
      return 0;
    }
    return ret;
  }
};


int main() {
  std::cout << Solution().myAtoi("- 123*241") << std::endl;
  return 0;
}
