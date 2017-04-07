/*   Implement strStr().
 *   Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    size_t m = haystack.size(), n = needle.size();
    if (!n) return 0;
    if (n > m) return -1;
    for (size_t i = 0; i < m - n; ++i) {
      if (haystack.at(i) != needle.at(0)) continue;
      if (haystack.substr(i, n) == needle) return i;
    }
    return -1;
  }
};

int main() {
  return 0;
}
