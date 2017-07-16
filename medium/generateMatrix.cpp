/*  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 *  For example,
 *    Given n = 3,
 *    You should return the following matrix:
 *    [
 *      [ 1, 2, 3 ],
 *      [ 8, 9, 4 ],
 *      [ 7, 6, 5 ]
 *    ]
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    int x = 0, y = -1, row = n, col = n, k = 0, dir = 0;
    while (k < n * n) {
      switch (dir) {
        case 0: {
          for (int i = 0; i < col; i++)
            res[x][++y] = ++k;
          break;
        }
        case 1: {
          for (int i = 0; i < row; i++)
            res[++x][y] = ++k;
          break;
        }
        case 2: {
          for (int i = 0; i < col; i++)
            res[x][--y] = ++k;
          break;
        }
        case 3: {
          for (int i = 0; i < row; i++)
            res[--x][y] = ++k;
          break;
        }
      }
      dir % 2 ? col-- : row--;
      dir = (dir + 1) % 4;
    }
    return res;
  }
};

int main() {
  Solution solute;
  auto res = solute.generateMatrix(3);
  for (auto r : res) {
    for (auto i : r) {
      std::cout << i << '\t';
    }
    std::cout << std::endl;
  }
  return 0;
}
