/*  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 *  For example,
 *    S = "ADOBECODEBANC"
 *    T = "ABC"
 *  Minimum window is "BANC".
 *
 *  Note:
 *  If there is no such window in S that covers all characters in T, return the empty string "".
 *  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.  
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

// general, for most substring problem,a solution is to use a hashmap assisted with two pointers.
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::map<char, int> num;
    for (auto c : t) num[c]++;

    size_t count =  t.size(), begin = 0, end = 0, l = INT_MAX, head = 0;
    while (end < s.length()) {
      if (num[s[end++]]-- > 0) count--;
      while (count == 0) {
        if (end - begin < l) l = end - (head = begin);
        if (num[s[begin++]]++ == 0) count++;
      }
    }
    return l == INT_MAX ? "" : s.substr(head, l);
  }
};

int main() {
  Solution solute;
  auto res = solute.minWindow("DOBECODEBANC", "ABC");
  std::cout << res << "\n";
  return 0;
}
