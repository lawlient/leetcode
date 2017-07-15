/*  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 *  For example,
 *  Given the following matrix:
 *  [
 *    [ 1, 2, 3 ],
 *    [ 4, 5, 6 ],
 *    [ 7, 8, 9 ]
 *  ]
 *
 *  You should return [1,2,3,6,9,8,7,4,5]. 
 *   
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) return std::vector<int>();
    int x = 0, y = -1, m = matrix.size(), n = matrix[0].size();
    int row = m, col = n;
    unsigned dir = 0;
    std::vector<int> res(m * n, 0);
    int k = 0;
    while (k < m*n) {
      switch(dir) {
        case 0: { // left -> right
          for (int i = 0; i < col; i++) {
            res[k++] = matrix[x][++y];
          }
          row--;
          dir = 1;
          break;
        }
        case 1: { // up -> down
          for (int i = 0; i < row; i++) {
            res[k++] = matrix[++x][y];
          }
          col--;
          dir = 2;
          break;
        }
        case 2: { // right -> left 
          for (int i = 0; i < col; i++) {
            res[k++] = matrix[x][--y];
          }
          row--;
          dir = 3;
          break;
        }
        case 3: { // down -> up
          for (int i = 0; i < row; i++) {
            res[k++] = matrix[--x][y];
          }
          col--;
          dir = 0;
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = solute.spiralOrder(input);
  for (auto r : res) {
    std::cout << r << '\t';
  }
  std::cout << std::endl;
  return 0;
}
