/*   The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *   Given an integer n, return all distinct solutions to the n-queens puzzle.
 *   Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 *   For example,
 *     There exist two distinct solutions to the 4-queens puzzle:
 *     [
 *       [".Q..",  // Solution 1
 *        "...Q",
 *        "Q...",
 *        "..Q."],
 *
 *       ["..Q.",  // Solution 2
 *        "Q...",
 *        "...Q",
 *        ".Q.."]
 *     ]
 *   
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
  bool isValid(const std::vector<std::string> &s, 
               const int &row, const int &col, const int &n) {
    for (int i = 0; i < row; i++)
      if (s[i][col] == 'Q')
        return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
      if (s[i][j] == 'Q')
        return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
      if (s[i][j] == 'Q')
        return false;
    return true;
  }

  void solve(std::vector<std::vector<std::string>> &result,
             std::vector<std::string> &s, int i, int n) {
    if (i == n) {
      result.push_back(s);
      return ;
    }
    for (int column = 0; column < n; column++) {
      if (isValid(s, i, column, n)) {
        s[i][column] = 'Q';
        solve(result, s, i+1, n);
        s[i][column] = '.';
      }
    }
  }
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> s(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> result;
    solve(result, s, 0, n);
    return result;
  }
};

int main() {
  Solution solute;
  auto res = solute.solveNQueens(4);
  for (auto s : res) {
    for (auto i : s) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
