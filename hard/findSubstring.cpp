/*  You are given a string, s, and a list of words, words, that are all of the same length. 
 *  Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 *  For example, given:
 *    s: "barfoothefoobarman"
 *    words: ["foo", "bar"]
 *    You should return the indices: [0,9].
 *    (order does not matter). 
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    std::vector<int> res;
    int wl = words[0].size(), N = words.size(), L = s.size();
    for (int i = 0; i < L - wl * N + 1; i++) {
      std::map<std::string, int> index;
      for (auto &w : words)
        index[w]++;

      int j;
      for (j = i; j < i + wl * N; j += wl) {
        auto w = index.find(s.substr(j, wl));
        if (w == index.end() || w->second == 0)
          break;
        w->second--;
      }
      if (j == i + wl * N)
        res.push_back(i);
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::string s = "barfoothefoobarman";
  std::vector<std::string> words{"foo", "bar"};
  auto res = solute.findSubstring(s, words);
  for (auto i : res) {
    std::cout << i << "\t";
  }
  return 0;
}
