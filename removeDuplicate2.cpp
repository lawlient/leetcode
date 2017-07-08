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
  int removeDuplicates(std::vector<int> &nums) {
    for (auto i = nums.begin(); i < nums.end(); ++i) {
      for (auto j = i + 1; j < nums.end(); j++) {
        if (*j != *i) break;
        if (j - i > 1) nums.erase(j--);
      }
      while (i < nums.end() && *i == *(i+1)) i++;
    }
    return nums.size();
  }

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
