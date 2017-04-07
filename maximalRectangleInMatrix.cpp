/*  Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *
 *  For example, given the following matrix:
 *  1 0 1 0 0
 *  1 0 1 1 1
 *  1 1 1 1 1
 *  1 0 0 1 0
 *  Return 6. 
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
  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    std::vector<int> left(n, 0), right(n, n), hegith(n, 0);
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
      int cur_left = 0, cur_right = n;
      for (int j = 0; j < n; j++)
        hegith[j] = matrix[i][j] == '1' ? hegith[j]+1 : 0;

      for (int j = 0; j < n; j++)
        if (matrix[i][j] == '1')
          left[j] = std::max(left[j], cur_left);
        else {
          left[j] = 0;
          cur_left = j + 1;
        }

      for (int j = n-1; j >= 0; j--)
        if (matrix[i][j] == '1')
          right[j] = std::min(right[j], cur_right);
        else {
          right[j] = n;
          cur_right = j;
        }

      for (int j = 0; j < n; j++)
        maxArea = std::max(maxArea, (right[j] - left[j]) * hegith[j]);
    }
    return maxArea;
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<char>> input{{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
  auto res = solute.maximalRectangle(input);
  std::cout << res << "\n";
  return 0;
}
