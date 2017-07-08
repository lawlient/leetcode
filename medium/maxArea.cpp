/*  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 *  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 *  Find two lines, which together with x-axis forms a container,
 *  such that the container contains the most water.  
 *  Note: You may not slant the container and n is at least 2. 
 *
*/

/* 
 *  
 *  
 *  
*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <list>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int i = 0, j = height.size() - 1, max = 0;
    while (i < j) {
      int area = (j - i) * std::min(height[i], height[j]);
      max = std::max(max, area);
      if (height[i] < height[j]) {
        int p = i++;
        while (i < j && height[p] >= height[i]) i++;
      } else {
        int p = j--;
        while (i < j && height[p] >= height[j]) j--;
      }
    }
    return max;
  }
};

int main() {
  std::vector<int> input{1, 2};
  std::cout << Solution().maxArea(input) << std::endl;
  return 0;
}
