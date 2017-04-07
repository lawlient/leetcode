/*  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.size() == 0) return true;
    if (s.size() % 2 == 1) return false;
    std::vector<char> stack;
    char first = s.at(0);
    if (first == ')' || first == ']' || first == '}') return false;
    stack.push_back(first);
    for (size_t i = 1; i < s.size(); ++i) {
      char c = s.at(i);
      switch (c) {
        case '(':
        case '[':
        case '{': stack.push_back(c); break;
        case ')': {
          if (stack.back() == '(')
            stack.pop_back();
          else return false;
          break;
        }
        case ']': {
          if (stack.back() == '[')
            stack.pop_back();
          else return false;
          break;
        }
        case '}': {
          if (stack.back() == '{')
            stack.pop_back();
          else return false;
          break;
        }
        default: return false;
      }
    }
    return stack.empty() ? true : false;
  }
};

int main() {
  Solution solute;
  std::cout << solute.isValid("([)]{}") << std::endl;
  return 0;
}
