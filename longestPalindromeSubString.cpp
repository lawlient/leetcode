/*  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 *  Example:
 *    Input: "babad"
 *    Output: "bab"
 *
 *  Note: "aba" is also a valid answer.
 *  
 *  Example:
 *    Input: "cbbd"
 *    Output: "bb"
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {

public:
  std::string longestPalindrome(std::string s) {
    size_t length = s.size();
    if (length < 2) return s;
    size_t b = 0, max = 1;
    size_t l = 0, r = 0;
    for (size_t i = 0; i < length && length - i > max / 2;) {
      l = r = i;
      while (r < length - 1 && s[r+1] == s[r]) r++;
      i = r + 1;
      while (r < length - 1 && l > 0 && s[l-1] == s[r+1]) {
        l--;
        r++;
      }
      if (max < r - l + 1) {
        max = r - l + 1;
        b = l;
      }
    }
    return s.substr(b, max);
  }
};

int main() {
  Solution sol;
  std::string s = "cbbd";
  std::cout << s << " : " << sol.longestPalindrome(s) << std::endl;
  return 0;
}
