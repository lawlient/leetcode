/*   Given two words word1 and word2, find the minimum number of steps required to
 *   convert word1 to word2. (each operation is counted as 1 step.)
 *   You have the following 3 operations permitted on a word:
 *   a) Insert a character
 *   b) Delete a character
 *   c) Replace a character
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

// dynamic programming
// dp[i][j] to be the minimum number of operations to convert word1[0..i-1] to word2[0..j-1]
class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int m = word1.size(), n = word2.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) dp[i][0] = i;
    for (int j = 1; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i-1] == word2[j-1]) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = std::min(dp[i-1][j-1] + 1, std::min(dp[i-1][j] + 1, dp[i][j-1] + 1));
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution solute;
  std::string s1 = "good";
  std::string s2 = "greed";

  auto res = solute.minDistance(s1, s2);
  std::cout << res << std::endl;
  return 0;
}
