/*  Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 *  determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
 *  You may assume the dictionary does not contain duplicate words.
 *  
 *  For example, givens = "leetcode",dict = ["leet", "code"].
 *  Return true because "leetcode" can be segmented as "leet code". 
 *
 *
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    int n = s.size();
    std::vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = i-1; j >= 0; j--) {
        if (dp[j]) {
          auto w = s.substr(j, i-j);
          if (wordDict.end() != std::find(wordDict.begin(), wordDict.end(), w)) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution solute;
  std::string s = "leetcode";
  std::vector<std::string> wordDict{"leet", "code"};
  auto res = solute.wordBreak(s, wordDict);
  std::cout << res << std::endl;
  return 0;
}
