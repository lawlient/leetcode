/*  The count-and-say sequence is the sequence of integers beginning as follows:
 *  1, 11, 21, 1211, 111221, ...
 *  1 is read off as "one 1" or 11.
 *  11 is read off as "two 1s" or 21.
 *  21 is read off as "one 2, then one 1" or 1211.
 *
 *  Given an integer n, generate the nth sequence.
 *  Note: The sequence of integers will be represented as a string.
 *  Subscribe to see which companies asked this question.
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

class Solution {
  std::string countAndSay(int n) {
    if (n == 0) return "";
    std::string res = "1";
    while (--n) {
      std::string tmp{};
      for (int i = 0; i < res.size(); i++) {
        int count = 1;
        while ((i+1 < res.size()) && (res[i] == res[i+1])) {
          count++;
          i++;
        }
        tmp += std::to_string(count) + res[i];
      }
      res = tmp;
    }
    return res;
  }
};

int main() {
  return 0;
}
