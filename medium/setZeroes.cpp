/*  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
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
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int last_exist_0_row = -1;
    for (int i = m - 1; i >= 0 && last_exist_0_row == -1; i--) {
      if (std::count(matrix[i].begin(), matrix[i].end(), 0)) {
        last_exist_0_row = i;
        break;
      }
    }
    if (last_exist_0_row == -1) return;

    for (int i = 0; i < last_exist_0_row; i++) {
      bool exist_0 = false;
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[last_exist_0_row][j] = 0;
          exist_0 = true;
        }
      }
      if (exist_0)
        std::fill(matrix[i].begin(), matrix[i].end(), 0);
    }

    for (int j = 0; j < n; j++) {
      if (matrix[last_exist_0_row][j] == 0) {
        for (int i = 0; i < m; i++) {
          matrix[i][j] = 0;
        }
      }
    }

    std::fill(matrix[last_exist_0_row].begin(), matrix[last_exist_0_row].end(), 0);
  }
};

int main() {
  Solution solute;
  std::vector<std::vector<int>> input{{1, 1, 1}, {1, 0, 1}};
  solute.setZeroes(input);
  for (auto s : input) {
    for (auto i : s) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
