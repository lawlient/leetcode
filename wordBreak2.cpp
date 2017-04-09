/*  Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 *  add spaces in s to construct a sentence where each word is a valid dictionary word. 
 *  You may assume the dictionary does not contain duplicate words.
 *  Return all such possible sentences.
 *  
 *  For example, given
 *  s = "catsanddog",
 *  dict = ["cat", "cats", "and", "sand", "dog"].
 *  A solution is ["cats and dog", "cat sand dog"]. 
 *
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
  std::vector<std::string> wordBreak(std::string s,std::vector<std::string> &wordDict) {
    std::unordered_map<int, std::vector<std::string>> memo{{s.size(), {""}}};
    std::function<std::vector<std::string>(int)> sentences = [&](int i) {
      if (!memo.count(i))
        for (int j = i+1; j <= s.size(); j++)
          if (std::find(wordDict.begin(), wordDict.end(), s.substr(i, j-i))
              != wordDict.end())
            for (auto tail : sentences(j))
              memo[i].push_back(s.substr(i, j-i) + (tail == "" ? "" : ' ' + tail));
      return memo[i];
    };
    return sentences(0);
  }
};

int main() {
  Solution solute;
  std::string s = "catsanddog";
  std::vector<std::string> wordDict{"cat", "cats", "and", "sand", "dog"};
  auto res = solute.wordBreak(s, wordDict);
  for (const auto &s : res) {
    std::cout << s << "\t";
  }
  std::cout << '\n';
  return 0;
}
