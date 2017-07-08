/*  Given a digit string, return all possible letter combinations that the number could represent. 
 *  A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *  Input:Digit string "23"
 *  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
  std::vector<std::string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno",
                                    "pqrs", "tuv", "wxyz"};

public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> res;
    if (digits.empty()) return res;
    res.push_back("");
    for (auto &n : digits) {
      std::vector<std::string> tmp;
      for (auto &c : keyboard[n - '0'])
        for (auto &s : res) 
          tmp.push_back(s+c);
      tmp.swap(res);
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::string i = "23";
  for (auto r : solute.letterCombinations(i)) {
    std::cout << r << std::endl;
  }
  return 0;
}
