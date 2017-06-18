/*  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 *  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 *  You may assume all four edges of the grid are all surrounded by water.
 *
 *  Example 1:
 *  
 *  11110
 *  11010
 *  11000
 *  00000
 *  
 *  Answer: 1
 *  
 *  Example 2:
 *  
 *  11000
 *  11000
 *  00100
 *  00011
 *  
 *  Answer: 3
 *  
 *  
 *
 *
*/

/*  
 *  
 *  
 *  
*/

#include <iostream>
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
  int m, n;

  void DFSmarking(std::vector<std::vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
    grid[i][j] = '0';
    DFSmarking(grid, i-1 , j);
    DFSmarking(grid, i+1 , j);
    DFSmarking(grid, i , j-1);
    DFSmarking(grid, i , j+1);
  }
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int count = 0;
    n = grid.size();
    if (n == 0) return count;
    m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1') {
          DFSmarking(grid, i, j);
          count++;
        }
      }
    }
    return count;
  }
};
