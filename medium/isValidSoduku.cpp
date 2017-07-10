/*  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
  bool isValidSuduko(std::vector<std::vector<char>> &board) {
    int checkRow[9][9] = {0};
    int checkCol[9][9] = {0};
    int checkSub[9][9] = {0};
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          int k = i/3 * 3 + j/3; // index in sub
          if (checkRow[i][num] || checkCol[j][num] || checkSub[k][num])
            return false;
          checkRow[i][num] = checkCol[j][num] = checkSub[k][num] = 1;
        }
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
