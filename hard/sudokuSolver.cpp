/*  Write a program to solve a Sudoku puzzle by filling the empty cells.
 *  Empty cells are indicated by the character '.'.
 *  You may assume that there will be only one unique solution. 
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <bitset>

class Solution {
  struct cell {
    uint8_t value;
    uint8_t numPossibilities;
    std::bitset<10> constraints;
    cell() : value(0), numPossibilities(9), constraints() {};
  };
  std::array<std::array<cell, 9>, 9> cells;

  bool set(int i, int j, int v) {
    cell &c = cells[i][j];
    if (c.value == v) return true;
    if (c.constraints[v]) return false;
    c.constraints = std::bitset<10>(0x3FE);
    c.constraints.reset(v);
    c.numPossibilities = 1;
    c.value = v;

    for (int k = 0; k < 9; k++) {
      if (i != k && !updateConstraints(k, j, v)) return false;
      if (j != k && !updateConstraints(i, k, v)) return false;
      int ix = i/3 * 3 + k/3;
      int jx = j/3 * 3 + k%3;
      if (ix != i && jx != j && !updateConstraints(ix, jx, v)) return false;
    }
    return true;
  }

  bool updateConstraints(int i, int j, int excludedValue) {
    cell &c = cells[i][j];
    if (c.constraints[excludedValue]) return true;
    if (c.value == excludedValue) return false;
    c.constraints.set(excludedValue);

    if (--c.numPossibilities > 1) return true;
    for (int v = 1; v <= 9; ++v) {
      if (!c.constraints[v]) {
        return set(i, j, v);
      }
    }
    assert(false);
  }

  std::vector<std::pair<int, int>> bt;

  bool findValuesForEmptyCells() {
    bt.clear();
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (!cells[i][j].value) {
          bt.push_back(std::make_pair(i, j));
        }
      }
    }

    std::sort(bt.begin(), bt.end(), [this](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities; });
    return backtrack(0);
  }

  bool backtrack(int k) {
    if (k >= static_cast<int>(bt.size())) return true;
    int i = bt[k].first, j = bt[k].second;
    if (cells[i][j].value) return backtrack(k + 1);
    auto constraints = cells[i][j].constraints;
    auto snapshot(cells);
    for (int v = 1; v <= 9; v++) {
      if (!constraints[v]) {
        if (set(i, j, v)) {
          if (backtrack(k + 1))
            return true;
        }
        cells = snapshot;
      }
    }
    return false;
  }
public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    cells  = std::array<std::array<cell, 9>, 9>();
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
          return ;
      }
    }

    if (!findValuesForEmptyCells())
      return ;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; j++) {
        if (cells[i][j].value)
          board[i][j] = cells[i][j].value + '0';
      }
    }
  }
};

class Solution2 {
  bool isValid(std::vector<std::vector<char>> &board, int i, int j, int v) {
    for (int k = 0; k < 9; k++) {
      if (k != i && board[k][j] == v) return false;
      if (k != j && board[i][k] == v) return false;
      int ix = i / 3 * 3 + k / 3;
      int jx = j / 3 * 3 + k % 3;
      if (ix != i && jx != j && v == board[ix][jx])
        return false;
    }
    return true;
  }

  bool solveSudoku(std::vector<std::vector<char>> &board, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return solveSudoku(board, i+1, 0);
    if (board[i][j] != '.') return  solveSudoku(board, i, j+1);

    for (char c = '1'; c <= '9'; c++) {
      if (isValid(board, i, j, c)) {
        board[i][j] = c;
        if (solveSudoku(board, i, j+1))
          return true;
        board[i][j] = '.';
      }
    }
    return false;
  }
public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    solveSudoku(board, 0, 0);
  }
};

int main() {
  return 0;
}
