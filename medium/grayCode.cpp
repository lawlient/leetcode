/*  The gray code is a binary numeral system where two successive values differ in only one bit.
 *  Given a non-negative integer n representing the total number of bits in the code,
 *  print the sequence of gray code. A gray code sequence must begin with 0.
 *
 *  For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *    00 - 0
 *    01 - 1
 *    11 - 3
 *    10 - 2
 *  Note:
 *  For a given n, a gray code sequence is not uniquely defined.
 *  For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *  For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 *  
 *  
*/

/*  0 00
 *  0 01 
 *
 *  0 11
 *  0 10
 *
 *  1 10
 *  1 11
 *  1 01
 *  1 00
 *
 *
 *
 *
 *
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

class Solution {
public:
  std::vector<int> grayCode(int n) {
    std::vector<int> res{0};
    for (int i = 0; i < n; i++)
      for (int k = res.size() - 1; k >= 0; k--)
        res.push_back(res[k] | 1<<i);
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.grayCode(3);
  for (auto i : res) {
    std::cout << i << "\t";
  }
  std::cout << "\n";
  return 0;
}
