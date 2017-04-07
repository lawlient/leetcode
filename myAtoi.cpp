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

int myAtoi(std::string str) {
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


int main() {
  std::string s = "- 123*241";
  std::cout << s << "  ===>  " << myAtoi(s) << std::endl;
  return 0;
}
