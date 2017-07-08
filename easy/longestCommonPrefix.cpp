/*  Write a function to find the longest common prefix string amongst an array of strings. 
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    std::string res;
    if (strs.size() == 0) return res;
    size_t l = INT_MAX;
    for (auto &s : strs) 
      l = std::min(l, s.size());
    for (size_t i = 0; i < l; i++) {
      char c = strs[0][i];
      auto diff = [i, c](std::string &s) { return s[i] != c; };
      if (std::any_of(strs.begin(), strs.end(), diff))
        return res;
      res += c;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<std::string> s{"aca", "aca"};
  std::cout << solute.longestCommonPrefix(s) << std::endl;
  return 0;
}
