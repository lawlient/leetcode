/*  Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.  
 *
 *  Example: 
 *    Given nums = [2, 7, 11, 15], target = 9, 
 *    Because nums[0] + nums[1] = 2 + 7 = 9,
 *    return [0, 1].
 *
 *
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
  std::vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> res;
    auto begin = nums.begin();
    auto end = nums.end();
    for (auto b = begin, e = end; b != e; b++) {
      auto other = std::find(begin, end, target - *b);
      if (other != end && other != b) {
        res.push_back(b - begin);
        res.push_back(other - begin);
        break;
      }
    }
    return res;
  }
};

int main() {
}
