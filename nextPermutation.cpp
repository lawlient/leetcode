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

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    int i;
    for (i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) break;
    }
    std::reverse(nums.begin() + i + 1, nums.end());
    if (i == -1) return;
    auto itr = std::upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
    std::swap(nums[i], *itr);
  }
};

int main() {
  std::vector<int> param{4, 5, 6, 7, 0, 1, 2};
  Solution solute;
  solute.nextPermutation(param);
  for (auto p : param) {
    std::cout << p << "\t";
  }
  // auto res = solute.longestValidParentheses("()");
  // std::cout << res << std::endl;
  return 0;
}
