/*  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 *  For example,
 *  Given:
 *  s1 = "aabcc",
 *  s2 = "dbbca",
 *
 *  When s3 = "aadbbcbcac", return true.
 *  When s3 = "aadbbbaccc", return false. 
 *  
*/

/*  dynamic program
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

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3) return false;
    bool table[l1+1][l2+1];
    table[0][0] = true;

    for (int i = 1; i <= l1; i++) 
      table[i][0] = table[i-1][0] && s1[i-1] == s3[i-1];

    for (int j = 1; j <= l2; j++) 
      table[0][j] = table[0][j-1] && s2[j-1] == s3[j-1];

    for (int i = 1; i <= l1; i++) {
      for (int j = 1; j <= l2; j++) {
        table[i][j] = (table[i][j-1] && (s2[j-1] == s3[i+j-1])) ||
                      (table[i-1][j] && (s1[i-1] == s3[i+j-1]));
      }
    }
    return table[l1][l2];
  }

  bool isInterleave2(std::string s1, std::string s2, std::string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3) return false;
    bool table[l1+1][l2+1];
    for (int i = 0; i <= l1; i++) {
      for (int j = 0; j <= l2; j++) {
        if (!i && !j) table[0][0] = true;
        else if (i == 0) table[i][j] = table[i][j-1] && (s2[j-1] == s3[j-1]);
        else if (j == 0) table[i][j] = table[i-1][j] && (s1[i-1] == s3[i-1]);
        else table[i][j] = (table[i][j-1] && (s2[j-1] == s3[i+j-1])) ||
                           (table[i-1][j] && (s1[i-1] == s3[i+j-1]));
      }
    }
    return table[l1][l2];
  }

  // time limit exceeded
  bool isInterleave3(std::string s1, std::string s2, std::string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3) return false;
    if (l1 == 0) return s2 == s3;
    if (l2 == 0) return s1 == s3;
    if (s3[0] != s1[0] && s3[0] != s2[0]) return false;
    if (s3[0] == s1[0] && s3[0] != s2[0])
      return isInterleave(s1.substr(1,l1-1), s2, s3.substr(1, l3-1));
    if (s3[0] != s1[0] && s3[0] == s2[0])
      return isInterleave(s1, s2.substr(1,l2-1), s3.substr(1, l3-1));
    return isInterleave(s1.substr(1,l1-1), s2, s3.substr(1, l3-1)) ||
           isInterleave(s1, s2.substr(1,l2-1), s3.substr(1, l3-1));
  }
};

int main() {
  Solution solute;
  std::string s1 = "aabcc";
  std::string s2 = "dbbca";
  std::string s3 = "aadbbcbcac";
  std::string s4 = "dbbca";
  auto res = solute.isInterleave(s1, s2, s3);
  std::cout << res << "\n";
  return 0;
}
