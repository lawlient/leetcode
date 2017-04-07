/*  Given a roman numeral, convert it to an integer.
 *  Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {

std::map<char, int> base { {'I',    1}, {'V',   5},
                              {'X',   10}, {'L',  50},
                              {'C',  100}, {'D', 500},
                              {'M', 1000}};

public:
  int RomanToInt(std::string s) {
    int x = base[s.back()];
    for (int i = s.size() - 2; i >= 0; --i) {
      if (base[s.at(i)] >= base[s.at(i + 1)]) {
        x += base[s.at(i)];
      } else {
        x -= base[s.at(i)];
      }
    }
    return x;
  }
};

int main() {
  Solution sol;
  std::cout << sol.RomanToInt("MMC") << std::endl;
  return 0;
}
