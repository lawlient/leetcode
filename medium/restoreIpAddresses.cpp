/*  Given a string containing only digits, restore it by returning all possible valid IP address combinations.  
 *  For example:
 *  Given "25525511135", 
 *  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
 *
*/

/* 
 *  
 *  
 *  
*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <list>

class Solution {
  void help(std::vector<std::string> &res, std::string ip, const std::string &s, int i, int count) {
    if (count > 4) return;
    int size = s.size();
    if (count == 4 && i < size) return;
    if (count == 4 && i == size) {
      res.push_back(ip); 
      return;
    }
    for (int j = 1; j < 4; j++) {
      if (i + j > size) return;
      auto sub = s.substr(i, j);
      if ((sub[0] == '0' && sub.size() > 1) ||
          (j == 3 && std::stoi(sub) > 255))
        continue;
      help(res, ip + sub + (count == 3 ? "" : "."), s, i + j, count + 1);
    }
  }
public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> res;
    std::string ip;
    help(res, ip, s, 0, 0);
    return res;
  }
};

int main() {
  return 0;
}
