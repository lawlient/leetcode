/*  A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *  'A' -> 1
 *  'B' -> 2
 *  ...
 *  'Z' -> 26
 *
 *  Given an encoded message containing digits, determine the total number of ways to decode it.
 *  For example,
 *  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *  The number of ways decoding "12" is 2. 
 *  
*/

/*  dynamic program: s'[] note number of ways
 *    s'[i] = s'[i-1] + s'[i-2]
 *    if s[i] == 0 then s'[i-1] = 0
 *
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

// DP
class Solution {
public:
  int numDecodings2(std::string s) {
    int n = s.size();
    if (!n || s[0] == '0') return 0;
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') a = 0;

      if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
        a = a + b;
        b = a - b;
      } else
        b = a;
    }
    return a;
  }
};

int main() {
  Solution solute;
  std::string p = "10";
  auto res = solute.numDecodings2(p);
  std::cout << res << "\n";
  return 0;
}
