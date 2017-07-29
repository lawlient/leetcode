/*  Given a string S and a string T, count the number of distinct subsequences of T in S.
 *  A subsequence of a string is a new string which is formed from the original string by deleting
 *  some (can be none) of the characters without disturbing the relative positions of the 
 *  remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *  
 *  Here is an example:
 *  S = "rabbbit", T = "rabbit"
 *  Return 3. 
 *
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int numDistinct(std::string s, std::string t) {
    int m = t.size(), n = s.size();
    int index[m+1][n+1];
    for (int j = 0; j <= n; j++) index[0][j] = 1;
    for (int i = 1; i <= m; i++) index[i][0] = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        index[i][j] = index[i][j-1];
        if (t[i-1] == s[j-1])
          index[i][j] += index[i-1][j-1];
      }
    }
    return index[m][n];
  }
};

int main() {
  Solution solute;
  std::string s = "rabbbit", t = "rabbit";
  auto res = solute.numDistinct(s, t);
  std::cout << res << "\n";
  return 0;
}
