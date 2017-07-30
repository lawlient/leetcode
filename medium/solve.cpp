/*  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *  A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *  
 *  For example,
 *    X X X X
 *    X O O X
 *    X X O X
 *    X O X X
 *  
 *  After running your function, the board should be:
 *    X X X X
 *    X X X X
 *    X X X X
 *    X O X X
 *  
 *  
 *
*/

/*  First, check the four border of the matrix. If there is a element is
 *  'O', alter it and all its neighbor 'O' elements to '1'.
 *  Then ,alter all the 'O' to 'X'
 *  At last,alter all the '1' to 'O'
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
#include <queue>
#include <list>


class Solution {
  int row;
  int col;
  void check(std::vector<std::vector<char>> &board, int i, int j) {
    if (board[i][j] == 'O') {
      board[i][j] = '1';
      if (i > 1) check(board, i-1, j);     // up
      if (j > 1) check(board, i, j-1);     // left
      if (i+1 < row) check(board, i+1, j); // down
      if (j+1 < col) check(board, i, j+1); // right
    }
  }
public:
  void solve(std::vector<std::vector<char>> &board) {
    row = board.size();
    if (row == 0) return;
    col = board[0].size();
    for (int i = 0; i < row; i++) {
      check(board, i, 0);
      if (col > 1) check(board, i, col-1);
    }
    for (int j = 1; j+1 < col; j++) {
      check(board, 0, j);
      if (row > 1) check(board, row-1, j);
    }
    
    for (auto &line : board)
      std::replace(line.begin(), line.end(), 'O', 'X');

    for (auto &line : board)
      std::replace(line.begin(), line.end(), '1', 'O');
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<char>> input{{'X', 'X', 'X', 'X'},
                                       {'X', 'O', 'O', 'X'},
                                       {'X', 'X', 'O', 'X'},
                                       {'X', 'O', 'X', 'X'}};
  solute.solve(input);
  for (auto r : input) {
    for (auto c : r) {
      std::cout << c << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
