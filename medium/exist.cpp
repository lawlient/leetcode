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
  bool help(std::vector<std::vector<char>> &board, const std::string &word, 
            int i, int x, int y) {
    if (i == word.size()) return true;
    if (x < 0 || x >= m || y < 0 || y >= n || word[i] != board[x][y]) return false;
    char c = board[x][y];
    board[x][y] = '\0';
    if (help(board, word, i+1, x-1, y) ||
        help(board, word, i+1, x+1, y) ||
        help(board, word, i+1, x, y-1) ||
        help(board, word, i+1, x, y+1))
      return true;
    board[x][y] = c;
    return false;
  }
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (help(board, word, 0, i, j))
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
