/*  Compare two version numbers version1 and version2.
 *  If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *  
 *  You may assume that the version strings are non-empty and contain only digits and the . character.
 *  The . character does not represent a decimal point and is used to separate number sequences.
 *  For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *  
 *  Here is an example of version numbers ordering:
 *  
 *  0.1 < 1.1 < 1.2 < 13.37  
 *
*/

/*  
 *  
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <list>


class Solution {
public:
  int compareVersion(std::string version1, std::string version2) {
    int i = 0, j = 0;
    int n1 = 0, n2 = 0;
    while (i < version1.size() || j < version2.size()) {
      while (i < version1.size() && version1[i] != '.') {
        n1 = n1 * 10 + (version1[i++] - '0');
      }

      while (j < version2.size() && version2[j] != '.') {
        n2 = n2 * 10 + (version2[j++] - '0');
      }

      if (n1 < n2) return 1;
      if (n1 > n2) return -1;
      
      n1 = 0;
      n2 = 0;
      i++;
      j++;
    }
    return 0;
  }
};

int main() {
  std::string v1 = "2.1";
  std::string v2 = "3";
  std::cout << Solution().compareVersion(v1, v2) << std::endl;
}
