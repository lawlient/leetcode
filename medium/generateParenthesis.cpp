/*  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *  For example, given n = 3, a solution set is:
 *  [
 *    "((()))",
 *    "(()())",
 *    "(())()",
 *    "()(())",
 *    "()()()"
 *  ]
*/

/*  n : the number of rest (
 *  m : the number of rest dismatch (
 *  we can append a ')' if a '(' is dismatch at least
 *  we can append a '(' if we have not run out of '('.
 *
 *
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
  void addingPar(std::vector<std::string> &v, std::string str, int n, int m) {
    if (n == 0 && m == 0) {
      v.push_back(str);
      return ;
    }
    if (m > 0) addingPar(v, str + ")", n, m - 1);
    if (n > 0) addingPar(v, str + "(", n - 1, m + 1);
  }
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    addingPar(res, "", n, 0);
    return res;
  }
};

int main() {
  return 0;
}
