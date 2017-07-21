/*  Given n non-negative integers representing the histogram's
 *  bar height where the width of each bar is 1,
 *  find the area of largest rectangle in the histogram. 
 *  
 *  For example,
 *  Given heights = [2,1,5,6,2,3],
 *  return 10. 
 *  
 *  
 *  
*/

/*  we append a zero height at tail of heights in order to calculate all area
 *  std::stack<int> index; record index in heights
 *  the height is ascending order in stack all the time
 *  we just calculate area when the current height less than the height of stack top index;
 *  
 *
 *
 *
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <array>
#include <math.h>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    heights.push_back(0);
    int maxArea = 0;
    std::stack<int> index;
    for (int i = 0; i < heights.size(); i++) {
      // the loop to calculate all area at left of index i
      while (!index.empty() && heights[index.top()] > heights[i]) {
        int h = heights[index.top()];
        index.pop();

        int pos = index.empty() ? -1 : index.top();
        if (h * (i - pos - 1) > maxArea) {
          maxArea = h * (i - pos - 1);
        }
      }
      index.push(i);
    }
    return maxArea;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{2, 1, 5, 6, 2, 3};
  auto res = solute.largestRectangleArea(input);
  std::cout << res << "\t";
  std::cout << "\n";
  return 0;
}
