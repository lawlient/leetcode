/*  Given an array with n objects colored red, white or blue, sort them 
 *  so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *  
 *  Note:
 *    You are not suppose to use the library's sort function for this problem. 
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>


class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int i = 0, j = nums.size() - 1, k = 0;
    while (k <= j) {
      while (nums[k] == 2 && k < j) std::swap(nums[k], nums[j--]);
      while (nums[k] == 0 && k > i) std::swap(nums[k], nums[i++]);
      k++;
    }
  }
};

int main() {
  std::vector<int> input{1, 2, 0, 0, 1, 1, 2};
  Solution solute;
  // auto res = solute.sortColors(input);
  solute.sortColors(input);
  for (auto n : input) {
    std::cout << n << "\t";
  }
  std::cout << "\n";
  return 0;
}
