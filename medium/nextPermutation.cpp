/*   Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *   If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *   The replacement must be in-place, do not allocate extra memory.
 *
 *   Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 *     1,2,3 → 1,3,2 
 *     3,2,1 → 1,2,3
 *     1,1,5 → 1,5,1
 *  
*/

/*  1. find substr of descending order and reverse it and record the number X before the substr 
 *  2. swap X with first number greater than X in substr
 *
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    auto i = nums.end() - 1;
    while (i > nums.begin())
      if (*(i-1) < *i--) 
        break;
    std::reverse(i, nums.end());
    if (i == nums.begin()) return;
    auto itr = std::upper_bound(i, nums.end(), *(i-1));
    std::swap(*(i-1), *itr);
  }
};

int main() {
  std::vector<int> param{4, 5, 6, 7, 0, 1, 2};
  Solution solute;
  solute.nextPermutation(param);
  for (auto p : param) {
    std::cout << p << "\t";
  }
  return 0;
}
