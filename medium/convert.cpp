/*  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 *  (you may want to display this pattern in a fixed font for better legibility) 
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R 
 *
 *  And then read line by line: "PAHNAPLSIIGYIR" 
 *  Write the code that will take a string and make this conversion given a number of rows: 
 *  string convert(string text, int nRows); 
 *  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 *  
 *
*/

/*   *n = numRows
 *    Δ = 2n-2    1                           2n-1                         4n-3
 *    Δ =         2                     2n-2  2n                    4n-4   4n-2
 *    Δ =         3               2n-3        2n+1              4n-5       .
 *    Δ =         .           .               .               .            .
 *    Δ =         .       n+2                 .           3n               .
 *    Δ =         n-1 n+1                     3n-3    3n-1                 5n-5
 *    Δ = 2n-2    n                           3n-2                         5n-4
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
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;
    int size = s.size();
    std::string res{};
    for (int i = 0; i < numRows; i++) {
      int step1 = (numRows - i - 1) * 2;
      int step2 = i * 2;
      int pos = i;
      if (pos < size) res += s[pos];
      while (1) {
        pos += step1;
        if (pos >= size) break;
        if (step1) res += s[pos];
        pos += step2;
        if (pos >= size) break;
        if (step2) res += s[pos];
      }
    }
    return res;
  }
};

int main() {
  std::cout << Solution().convert("PAYPALISHIRING", 3) << std::endl;
  return 0;
}
