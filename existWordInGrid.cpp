/*  Given a 2D board and a word, find if the word exists in the grid.
 *  The word can be constructed from letters of sequentially adjacent cell,
 *  where "adjacent" cells are those horizontally or vertically neighboring.
 *  The same letter cell may not be used more than once.
 *
 *  For example,
 *  Given board =
 *  [
 *    ['A','B','C','E'],
 *    ['S','F','C','S'],
 *    ['A','D','E','E']
 *  ]
 *
 *  word = "ABCCED", -> returns true,
 *  word = "SEE", -> returns true,
 *  word = "ABCB", -> returns false.
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

class Solution {
  int m;
  int n;
  std::string s;
  bool isvalid(std::vector<std::vector<char>> &board,
               int i, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || s[i] != board[x][y])
      return false;
    if (s[i+1] == '\0')
      return true;
    char t = board[x][y];
    board[x][y] = '\0';
    if (isvalid(board, i+1, x-1, y) ||
        isvalid(board, i+1, x+1, y) ||
        isvalid(board, i+1, x, y-1) ||
        isvalid(board, i+1, x, y+1))
      return true;
    board[x][y] = t;
    return false;
  }
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    m = board.size(), n = board[0].size(), s = word;
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (isvalid(board, 0, x, y))
            return true;
      }
    }
    return false;
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<char>> input{{'A', 'B', 'C', 'E'},
                                       {'S', 'F', 'C', 'S'},
                                       {'A', 'D', 'E', 'E'}};
  auto res = solute.exist(input, "ABCCED");
  std::cout << res << "\n";
  return 0;
}
