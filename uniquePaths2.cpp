/*  Follow up for "Unique Paths":
 *  Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *  An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 *  For example,
 *  There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *  [
 *    [0,0,0],
 *    [0,1,0],
 *    [0,0,0]
 *  ]
 *  The total number of unique paths is 2.
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> record(m+1, std::vector<int>(n+1, 0));
    record[0][1] = 1;
    for (size_t i = 1; i <= m; i++) {
      for (size_t j = 1; j <= n; j++) {
        if (!obstacleGrid[i-1][j-1]) {
          record[i][j] = record[i-1][j] + record[i][j-1];
        }
      }
    }
    return record[m][n];
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<int>> input{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  auto res = solute.uniquePathsWithObstacles(input);
  std::cout << res << std::endl;
  return 0;
}
