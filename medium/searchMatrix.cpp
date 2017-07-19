/*  Write an efficient algorithm that searches for a value in an m x n matrix.
 *
 *  This matrix has the following properties:
 *  1) Integers in each row are sorted from left to right.
 *  2) The first integer of each row is greater than the last integer of the previous row.
 *
 *  For example,
 *  Consider the following matrix:
 *  [  
 *    [1,   3,  5,  7],
 *    [10, 11, 16, 20],
 *    [23, 30, 34, 50]
 *  ]
 *  Given target = 3, return true.
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
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int M = matrix[mid / n][mid % n];
      if (M == target) return true;
      if (M < target) l = mid + 1;
      else r = mid - 1;
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> input{{1, 3, 5, 7},
                                      {10, 11, 16, 20},
                                      {23, 30, 34, 50}};
  std::vector<std::vector<int>> input2{{1}};
  Solution solute;
  auto res = solute.searchMatrix(input, 1);
  std::cout << res << std::endl;
  return 0;
}
