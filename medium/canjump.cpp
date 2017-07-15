/*  Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *  Each element in the array represents your maximum jump length at that position.
 *  Determine if you are able to reach the last index.
 *  For example:
 *    A = [2,3,1,1,4], return true.
 *    A = [3,2,1,0,4], return false. 
 *
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
  bool canjump(std::vector<int> &nums) {
    int b = 1,  e = nums[0];
    for (int i = b; i <= e; i++) {
      e = std::max(nums[i]+i, e);
      if (e+1 >= nums.size())
        return true;
    }
    return e+1 == nums.size();
  }
};

int main() {
  Solution solute;
  std::vector<int> input1{0};
  std::vector<int> input2{3, 2, 1, 0, 4};
  auto res1 = solute.canjump(input1);
  auto res2 = solute.canjump(input2);
  std::cout << res1 << '\n';
  std::cout << res2 << '\n';
  return 0;
}
