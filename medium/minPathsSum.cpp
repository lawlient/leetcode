/*  Given a m x n grid filled with non-negative numbers, find a path from
 *  top left to bottom right which minimizes the sum of all numbers along its path.
 *
 *  Note: You can only move either down or right at any point in time.
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
  int minPathsSum(std::vector<std::vector<int>> &grid) {
    size_t m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> mem(m, std::vector<int>(n, 0));
    mem[0][0] = grid[0][0];
    for (size_t i = 1; i < n; i++) mem[0][i] = grid[0][i] + mem[0][i-1];
    for (size_t i = 1; i < m; i++) mem[i][0] = grid[i][0] + mem[i-1][0];
    for (size_t i = 1; i < m; i++)
      for (size_t j = 1; j < n; j++)
        mem[i][j] = grid[i][j] + std::min(mem[i-1][j], mem[i][j-1]);
    return mem[m-1][n-1];
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<int>> input{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  auto res = solute.minPathsSum(input);
  std::cout << res << std::endl;
  return 0;
}
