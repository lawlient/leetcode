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
  bool isValid(const std::vector<int> &one, int i, int j) {
    int k = 0;
    while (k < i) {
      if (one[k] == j || std::abs(one[k] - j) == std::abs(i - k))
        return false;
      k++;
    }
    return true;
  }

  void findSolve(std::vector<int> &one, int i, int &count, int n) {
    if (i == n) {
      count++;
      return;
    }
    for (int j = 0; j < n; j++) {
      one[i] = j;
      if (isValid(one, i, j)) {
        findSolve(one, i+1, count, n);
      }
    }
  }
public:
  // non-recursive
  int totalNQueens(int n) {
    int count = 0;
    std::vector<int> one(n, -1);
    int row = 0, col = 0;
    while (row < n) {
      while (col < n) {
        if (isValid(one, row, col)) {
          one[row] = col;
          if (row == n-1) {
            count++;
            col++;
          } else {
            col = 0;
            break;
          }
        } else {
          col++;
        }
      }
      if (col == n) {
        row--;
        if (row < 0) break;
        col = one[row]+1;
        continue;
      }
      row++;
    }
    return count;
  }

  // recursive
  int solveNQueens(int n) {
    int count = 0;
    std::vector<int> one(n, -1);
    findSolve(one, 0, count, n);
    return count;
  }
};

int main() {
  Solution solute;
  auto res = solute.solveNQueens(4);
  std::cout << res << std::endl;
  return 0;
}
