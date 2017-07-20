/*  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *  Write a function to determine if a given target is in the array.
 *  The array may contain DUPLICATES.
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

class Solution {
public:
  bool search(std::vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) return true;
      if (nums[mid] > nums[r]) {
        if (nums[mid] > target && nums[l] <= target)
          r = mid;
        else 
          l = mid + 1;
      } else if (nums[mid] < nums[r]) {
        if (nums[mid] < target && nums[r] >= target)
          l = mid + 1;
        else 
          r = mid;
      } else r--;
    }
    return nums[l] == target ? true : false;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{4, 5, 5, 6, 7, 0, 1, 2};
  std::vector<int> input2{3, 1};
  auto res = solute.search(input2, 1);
  std::cout << res << "\n";
  return 0;
}
