/*   Given n non-negative integers representing an elevation map where the width of each bar is 1,
 *   compute how much water it is able to trap after raining.
 *   For example,
 *
 *   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
 *  
*/

/*  4 pointers 
 *    left : point to current left position
 *    maxLeft : reserve current max left
 *    right : point to current right position
 *    maxRight : reserve current max right
 *
 *  we just move the point of short one every step
 *  if current position shorter than max one
 *  then trap more water
 *  else update max point
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int maxLeft = 0, maxRight = 0;
    int res = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      if (height[left] <= height[right]) {
        if (height[left] > maxLeft)
          maxLeft = height[left];
        else
          res += maxLeft - height[left];
        left++;
      } else {
        if (height[right] > maxRight)
          maxRight = height[right];
        else
          res += maxRight - height[right];
        right--;
      }
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto res = solute.trap(input);
  std::cout << res << "\n";
  return 0;
}
