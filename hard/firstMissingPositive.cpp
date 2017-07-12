/*   Given an unsorted integer array, find the first missing positive integer.
 *   For example,
 *     Given [1,2,0] return 3,
 *     and [3,4,-1,1] return 2.
 *
 *   Your algorithm should run in O(n) time and uses constant space. 
 *  
*/

/*  n should at array[n-1]
 *  we should find first n != array[n-1]
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  int firstMissingPositive(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        std::swap(nums[i], nums[nums[i]-1]);
    }
    for (int i = 1; i <= n; ++i) {
      if (nums[i-1] != i)
        return i;
    }
    return n+1;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 0};
  auto res = solute.firstMissingPositive(input);
  std::cout << res << "\n";
  return 0;
}
