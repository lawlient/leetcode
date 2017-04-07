/*  You are given a string, s, and a list of words, words, that are all of the same length. 
 *  Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 *  For example, given:
 *    s: "barfoothefoobarman"
 *    words: ["foo", "bar"]
 *    You should return the indices: [0,9].
 *    (order does not matter). 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    int length_of_word = words[0].size(), N = words.size();
    int LAST = s.size() - length_of_word * N + 1;
    std::vector<int> res;
    for (int i = 0; i < LAST; ++i) {
      std::map<std::string, int> record;
      for (auto w : words) {
        record[w]++;
      }

      int j;
      for (j = i; j < i + N * length_of_word; j += length_of_word) {
        auto rec = record.find(s.substr(j, length_of_word));
        if (rec == record.end()) break;
        if (rec->second == 0) break;
        rec->second--;
      }
      if (j == i + N * length_of_word) {
        res.push_back(i);
      }
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
