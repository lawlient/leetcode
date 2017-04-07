/*  Given an array of words and a length L, format the text such that
 *  each line has exactly L characters and is fully (left and right) justified.
 *  You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 *  Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *  Extra spaces between words should be distributed as evenly as possible.
 *  If the number of spaces on a line do not divide evenly between words,
 *  the empty slots on the left will be assigned more spaces than the slots on the right.
 *  For the last line of text, it should be left justified and no extra space is inserted between words.
 *  For example,
 *  words: ["This", "is", "an", "example", "of", "text", "justification."]
 *  L: 16.
 *  Return the formatted lines as:
 *  [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 *  ]
 *  Note: Each word is guaranteed not to exceed L in length. 
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
  std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth) {
    std::vector<std::string> res;
    int l = 0;
    std::vector<std::string> line;
    for (size_t i = 0; i < words.size(); i++) {
      if (l + words[i].size() + line.size() > maxWidth) {
        std::string tmp("");
        if (line.size() == 1) {
          tmp = line[0] + std::string(maxWidth-line[0].size(), ' ');
        } else {
          int spaceN = maxWidth - l;
          int aver = spaceN / (line.size() - 1);
          for (size_t j = 0; j < line.size() - 1; j++) { line[j] += std::string(aver, ' '); }
          l = l + aver * (line.size() - 1);
          for (int j = 0; j < maxWidth - l; j++) { line[j] += ' '; }
          for (auto s : line) { tmp += s; }
        }
        res.push_back(tmp);
        l = 0;
        line.clear();
      }
      l += words[i].size();
      line.push_back(words[i]);
    }
    if (!line.empty()) {
      std::string tmp("");
      for (auto s : line) { tmp += s + ' '; }
      tmp += std::string(maxWidth, ' ');
      res.push_back(tmp.substr(0, maxWidth));
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<std::string> input{"This", "is", "an", "example", "of", "text", "justification."};
  std::vector<std::string> input2{""};

  auto res = solute.fullJustify(input2, 0);
  std::cout << "size of res = " << res.size() << std::endl;
  for (auto s : res) {
    std::cout << s << std::endl;
  }
  return 0;
}
