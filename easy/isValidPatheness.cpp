/*  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

class Solution {
  std::unordered_map<char, char> index{{')', '('}, {']', '['}, {'}', '{'}};
public:
  bool isValid(std::string s) {
    std::stack<char> pre;
    for (auto &c : s) {
      switch (c) {
        case '(' :
        case '[' :
        case '{' : pre.push(c); break;
        case ')' :
        case ']' :
        case '}' : if (pre.empty()) return false;
                   if (pre.top() == index[c]) pre.pop();
                   else return false;
                   break;
        default: break;
      }
    }
    return pre.empty();
  }
};

int main() {
  Solution solute;
  std::cout << solute.isValid("([)]{}") << std::endl;
  return 0;
}
