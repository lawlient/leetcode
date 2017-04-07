/*  Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 *  For example:
 *  Given "25525511135",
 *  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

class Solution {
  void recursive(std::vector<std::string> &all, const std::string &s,
                 std::string one, int pos, int count) {
    if (count > 4) return;
    int n = s.size();
    if (count == 4 && pos == n) all.push_back(one);
    for(int i = 1; i < 4; i++) {
      if (pos + i > n) break;
      std::string sub = s.substr(pos, i);
      if ((sub[0] == '0' && sub.size() > 1) ||
          (i == 3 && std::stoi(sub) >= 256)) 
        continue;
      recursive(all, s, one + sub + (count == 3 ? "" : "."), pos + i, count+1);
    }
  }
public:
  std::vector<std::string> restoreIpAddress(std::string s) {
    std::vector<std::string> res;
    std::string one("");
    recursive(res, s, one, 0, 0);
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.restoreIpAddress("25525511135");
  std::cout << res.size() << std::endl;
  for (auto ip : res) {
    std::cout << ip << "\n";
  }
  return 0;
}
