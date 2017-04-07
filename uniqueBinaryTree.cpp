/*  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 *  For example,
 *  Given n = 3, there are a total of 5 unique BST's.
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 *
 *
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int numTrees(int n) {
    std::vector<int> G(n+1, 0);
    G[0] = G[1] = 1;

    for (int i = 2; i <= n; i++) 
      for (int j = 1; j <= i; j++)
        G[i] += G[j-1] * G[i-j];

    return G[n];
  }
};

int main() {
  Solution solute;
  auto res = solute.numTrees(3);
  std::cout << res << "\t";
  return 0;
}
