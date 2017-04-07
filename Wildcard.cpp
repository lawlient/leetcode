/*   Implement wildcard pattern matching with support for '?' and '*'.
 *        '?' Matches any single character.
 *        '*' Matches any sequence of characters (including the empty sequence).
 *   The matching should cover the entire input string (not partial).
 *   The function prototype should be:
 *     bool isMatch(const char *s, const char *p)
 *   
 *   Some examples:
 *     isMatch("aa","a") → false
 *     isMatch("aa","aa") → true
 *     isMatch("aaa","aa") → false
 *     isMatch("aa", "*") → true
 *     isMatch("aa", "a*") → true
 *     isMatch("ab", "?*") → true
 *     isMatch("aab", "c*a*b") → false
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int s_l = s.length(), p_l = p.length();
    int i = 0, j = 0, star = -1, match = 0;
    while (i < s_l) {
      if (j < p_l && p[j] == '*') {
        match = i;
        star = j++;
      } else if (j < p_l && (p[j] == '?' || p[j] == s[i])) {
        i++;
        j++;
      } else if (star >= 0) {
        i = ++match;
        j = star + 1;
      } else {
        return false;
      }
    }
    while (j < p_l && p[j] == '*') {
      j++;
    }
    return j == p_l;
  }
};

int main() {
  Solution solute;
  std::string s = "aa", p = "aab";
  auto res = solute.isMatch(s, p);
  std::cout << res << "\n";
  return 0;
}
