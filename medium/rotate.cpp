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
    for (int i = 0; i < matrix.size(); i++)
      for (int j = i+1; j < matrix[0].size(); j++)
        std::swap(matrix[i][j], matrix[j][i]);

    for (auto &v : matrix)
      std::reverse(v.begin(), v.end());
  }
};

int main() {
  return 0;
}
