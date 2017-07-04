/*  Given a string, find the length of the longest substring without repeating characters.  
 *
 *  Examples: 
 *    Given "abcabcbb", the answer is "abc", which the length is 3.  
 *    Given "bbbbb", the answer is "b", with the length of 1.
 *    Given "pwwkew", the answer is "wke", with the length of 3. 
 *
 *  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *  
 *  
 *  
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
  int lengthOfLongestSubstring(std::string s) {
    int maxLen = 0;
    int b = 0;
    std::vector<int> index(256, -1);
    for (int i = 0; i < s.size(); i++) {
      b = std::max(b, index[s[i]] + 1);
      index[s[i]] = i;
      maxLen = std::max(maxLen, i - b + 1);
    }
    return maxLen;
  }
};

int main() {
  std::string v1 = "abcabcbb";
  std::string v2 = "pwwkew";
  std::cout << Solution().lengthOfLongestSubstring(v2) << std::endl;
}
