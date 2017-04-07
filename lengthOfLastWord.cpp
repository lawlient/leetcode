/*  Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 *  return the length of last word in the string.
 *
 *  If the last word does not exist, return 0.
 *  Note: A word is defined as a character sequence consists of non-space characters only.
 *
 *  For example,
 *  Given s = "Hello World",
 *  return 5. 
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int length = s.size();
    int pos = s.find_last_not_of(' ', length);
    if (pos == -1) return 0;
    auto lastSpace = s.find_last_of(' ', pos);
    return pos - lastSpace;
  }
};

int main() {
  Solution solute;
  std::string k = " ";
  auto res = solute.lengthOfLastWord(k);
  std::cout << res << '\n';
  return 0;
}
