/*  You are given an n x n 2D matrix representing an image.
 *  Rotate the image by 90 degrees (clockwise).
 *
 *  Follow up:
 *  Could you do this in-place?
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    size_t n = matrix.size();
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (size_t l = 0; l < n; ++l) {
      std::reverse(matrix[l].begin(), matrix[l].end());
    }
  }
};

int main() {
  return 0;
}
