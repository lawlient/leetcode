/*  Implement regular expression matching with support for '.' and '*'.
 *  
 *  '.' Matches any single character.
 *  '*' Matches zero or more of the preceding element.
 *  
 *  The matching should cover the entire input string (not partial).
 *  
 *  The function prototype should be:
 *  bool isMatch(const char *s, const char *p)
 *  
 *  Some examples:
 *  isMatch("aa","a") ? false
 *  isMatch("aa","aa") ? true
 *  isMatch("aaa","aa") ? false
 *  isMatch("aa", "a*") ? true
 *  isMatch("aa", ".*") ? true
 *  isMatch("ab", ".*") ? true
 *  isMatch("aab", "c*a*b") ? true
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Solution {
  bool isMatch(std::string s, int i, std::string p, int j) {
    int sl = s.length(), pl = p.length();
    if (j == pl) {
        return i == sl;
    }
    if (j == pl - 1 || p[j + 1] != '*') {
      if (i == sl || (s[i] != p[j] && p[j] != '.')) 
        return false;
      return isMatch(s, i + 1,p,  j + 1);
    }
    while (i < sl && (s[i] == p[j] || p[j] == '.')) {
      if (isMatch(s, i, p, j + 2)) {
        return true;
      }
      i++;
    }
    return isMatch(s, i, p, j + 2);
  }
public:
  bool isMatch(std::string s, std::string p) {
    return isMatch(s, 0, p, 0);
  }
};

int main() {
  std::string s = "aab", p = "c*a*b";
  std::cout << Solution().isMatch(s, p) << std::endl;
  return 0;
}
