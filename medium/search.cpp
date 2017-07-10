/*  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *  You are given a target value to search. If found in the array return its index, otherwise return -1.
 *  You may assume no duplicate exists in the array.
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      auto m = l + (r - l) / 2;
      nums[m] > nums[r] ? l = m + 1 : r = m;
    }
    int rotate = l;
    l = 0, r = nums.size() - 1;
    while (l <= r) {
      auto m = l + (r - l) / 2;
      auto pos = (m + rotate) % nums.size();
      if (nums[pos] == target) return pos;
      nums[pos] < target ? l = m + 1 : r = m - 1;
    }
    return -1;
  }
};

int main() {
  std::vector<int> param{4, 5, 6, 7, 0, 1, 2};
  Solution solute;
  auto res = solute.search(param, 6);
  std::cout << res << std::endl;
  return 0;
}
