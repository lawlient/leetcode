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

/*  for : 0 -> n
 *  1. find all same continuous char(jump step)
 *  2. if left char == right char
 *     then max + 2 do step 2
 *     else the string length and the current max length
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {

public:
  std::string longestPalindrome(std::string s) {
    int size = s.size();
    if (size < 2) return s;
    int b = 0, max = 1;
    for (int i = 0; i < size && size - i > max / 2;) {
      int l = i, r = i;
      while (r < size - 1 && s[r+1] == s[r]) r++;
      i = r + 1;
      while (r < size - 1 && l > 0 && s[l-1] == s[r+1]) {
        l--;
        r++;
      }
      if (max < r - l + 1) {
        b = l;
        max = r - l + 1;
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
