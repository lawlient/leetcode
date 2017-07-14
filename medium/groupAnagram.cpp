/*  Given an array of strings, group anagrams together.
 *
 *  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 *  Return:
 *  [
 *    ["ate", "eat","tea"],
 *    ["nat","tan"],
 *    ["bat"]
 *  ]
 *  Note: All inputs will be in lower-case.
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (const auto &s : strs) {
      auto backup = s;
      std::sort(backup.begin(), backup.end());
      mp[backup].push_back(s);
    }
    std::vector<std::vector<std::string>> res;
    for (const auto &r : mp) {
      res.push_back(r.second);
    }
    return res;
  }
};

int main() {
  std::vector<std::string> input{"ate", "bat", "eat", "nat", "tan", "tea"};
  Solution solute;
  auto res = solute.groupAnagrams(input);
  for (auto g : res) {
    for (auto s : g) {
      std::cout << s << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
