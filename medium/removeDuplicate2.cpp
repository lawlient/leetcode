/*  Follow up for "Remove Duplicates":
 *  What if duplicates are allowed at most twice?
 *  
 *  For example,
 *    Given sorted array nums = [1,1,1,2,2,3],
 *    Your function should return length = 5, with the first five elements of
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
  // tivial
  int removeDuplicates(std::vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] != nums[i+1]) continue;
      i++;
      while (nums[i] == nums[i+1])
        nums.erase(i+1+nums.begin());
    }
    return nums.size();
  }

  // pretty
  int removeDuplicates2(std::vector<int> &nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++) {
      if (nums[i] == nums[i - count - 2])
        count++;
      else
        nums[i-count] = nums[i];
    }
    return n - count;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 2, 2, 2, 2, 3};
  auto res = solute.removeDuplicates(input);
  std::cout << res << "\n";
  return 0;
}
