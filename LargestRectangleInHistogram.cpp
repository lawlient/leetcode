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

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    heights.push_back(0);
    int minArea = 0;
    std::vector<int> index;
    for (int i = 0; i < heights.size(); i++) {
      while (!index.empty() && heights[index.back()] >= heights[i]) {
        int h = heights[index.back()];
        index.pop_back();

        int pos = index.empty() ? -1 : index.back();
        if (h * (i - pos - 1) > minArea) {
          minArea = h * (i - pos - 1);
        }
      }
      index.push_back(i);
    }
    return minArea;
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
