/*   Implement strStr().
 *   Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    int l = static_cast<int>(haystack.size()) - needle.size() + 1;
    for (int i = 0; i < l; i++) {
      int k = 0;
      while (k < needle.size()) {
        if (needle[k] != haystack[i+k])
          break;
        k++;
      }
      if (k == needle.size())
        return i;
    }
    return -1;
  }
};

int main() {
  std::cout << Solution().strStr("ba", "a") << std::endl;
  return 0;
}
