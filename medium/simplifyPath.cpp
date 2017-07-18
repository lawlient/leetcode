/*  Given an ABSOLUTE path for a file (Unix-style), simplify it.
 *
 *  For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> p;
    for (size_t b = 0; b < path.length();)  {
      size_t next = path.find_first_of('/', b+1);
      std::string s = path.substr(b, next-b);
      if (s == "/." || s == "/") ;
      else if (s == "/..") {
        if (!p.empty())
          p.pop_back();
      } else {
        p.push_back(s);
      }
      b = next;
    }
    std::string res;
    for (const auto &s : p) {
      res += s;
    }
    if (res == "") res = "/";
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.simplifyPath("/..");
  std::cout << res << "\t";
  return 0;
}
