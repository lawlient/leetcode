/*  The set [1,2,3,…,n] contains a total of n! unique permutations.
 *  By listing and labeling all of the permutations in order,
 *  We get the following sequence (ie, for n = 3):
 *
 *  "123"
 *  "132"
 *  "213"
 *  "231"
 *  "312"
 *  "321"
 *  
 *  Given n and k, return the kth permutation sequence.
 *  Note: Given n will be between 1 and 9 inclusive.
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
  std::string getPermutation(int n, int k) {
    std::string s(std::string("123456789").substr(0, n));
    int f = 1;
    for (int i = 0; i < n; i++) f *= i+1;
    k--;
    for (int i = 0; i < n; i++) {
      f /= n - i;
      int j = i + k/f;
      char c = s[j];
      while (j > i) {
        s[j] = s[j-1];
        j--;
      }
      k %= f;
      s[i] = c;
    }
    return s;
  }
};

int main() {
  Solution solute;
  auto res = solute.getPermutation(3, 3);
  std::cout << res << "\n";
  return 0;
}
