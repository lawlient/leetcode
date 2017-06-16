/*  Given an input string, reverse the string word by word.  
 *  For example,
 *    Given s = "the sky is blue",
 *    return "blue is sky the". 
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
  void reverseWords(std::string &s) {
    int i = 0, j = 0;
    int l = 0;
    int len = s.length();
    int wc = 0;

    while (true) {
      while (i < len && s[i] == ' ') i++;
      if (i == len) break;
      if (wc) s[j++] = ' ';
      l = j;
      while (i < len && s[i] != ' ') s[j++] = s[i++];
      std::reverse(s.begin() + l, s.begin() + j);
      wc++;
    }

    s.resize(j);
    std::reverse(s.begin(), s.begin() + j);
  }
};

int main() {
  Solution solute;
  std::string s = "the sky is blue";
  solute.reverseWords(s);
  std::cout << s << std::endl;
}
