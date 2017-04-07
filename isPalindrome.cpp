/*  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *  For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 *  
 *  Note:
 *  Have you consider that the string might be empty? This is a good question to ask during an interview.
 *  For the purpose of this problem, we define empty string as valid palindrome.
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
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isPalindrome(std::string s) {
    int i = 0, j = s.size()-1;
    while (j > i) {
      while (!std::isalnum(s[i]) && i < j) i++;
      while (!std::isalnum(s[j]) && i < j) j--;
      if (std::toupper(s[i]) != std::toupper(s[j]))
        return false;
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  Solution solute;
  std::string s = "0p";
  auto res = solute.isPalindrome(s);
  std::cout << res << "\n";
  return 0;
}
