#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    std::string res("");
    std::vector<size_t> lengths;
    for (auto s : strs) { lengths.push_back(s.size()); }
    size_t min_length = *std::min_element(lengths.begin(), lengths.end());
    if (min_length == 0) return res;
    for (size_t i = 0; i < min_length; ++i) {
      bool isCommon = true;
      for (auto b = strs.begin() + 1, e = strs.end();
           b != e; b++) {
        if (b->at(i) != strs[0].at(i)) {
          isCommon = false;
          break;
        }
      }
      if (isCommon == true) {
        res += strs[0].at(i);
      } else break;
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<std::string> s{"aca", "cba"};
  std::cout << solute.longestCommonPrefix(s) << std::endl;
  return 0;
}
