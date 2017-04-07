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
    int m = s.size(), n = t.size();
    std::vector<int> tmp(n+1, 0);
    for (int j = 0; j <= m; j++) tmp[j] = 1;

    for (int i = 0; i < n; i++) {
      std::vector<int> next(n+1, 0);
      for (int j = 0; j < m; j++)
        next[j+1] = next[j] + ((t[i] == s[j]) ? tmp[j] : 0);
      std::swap(tmp, next);
    }

    return tmp[m];
  }
};

int main() {
  Solution solute;
  std::string s = "rabbbit", t = "rabbit";
  auto res = solute.numDistinct(s, t);
  std::cout << res << "\n";
  return 0;
}
