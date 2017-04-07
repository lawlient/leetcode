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
    int n = nums.size();
    int last0 = 0, first2 = n - 1;
    for (int i = 0; i <= first2; i++) {
      while (nums[i] == 2 && i < first2) std::swap(nums[i], nums[first2--]);
      while (nums[i] == 0 && i > last0) std::swap(nums[i], nums[last0++]);
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
