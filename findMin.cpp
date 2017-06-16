/*  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.  
 *  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).  
 *  Find the minimum element.  
 *  You may assume no duplicate exists in the array.
 *  
 *
*/

/*  
 *  
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <list>


class Solution {
public:
  // O(n)
  int findMin0(std::vector<int> &nums) {
    return *std::min_element(nums.begin(), nums.end());
  }

  // O(log n)
  int findMin1(std::vector<int> &nums) {
    unsigned l = 0, h = nums.size() - 1;
    while (l < h) {
      auto m = l + (h - l) / 2;
      nums[m] > nums[h] ? l = m + 1 : h = m;
    }
    return nums[l];
  }
};

int main() {
  std::vector<int> input{4, 5, 6, 7, 1, 2};
  std::cout << Solution().findMin1(input) << std::endl;
}
