/*  
 *  
 *  
 *  
 *  
 *
 *  
 *  
 *  
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int ladderLength1(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
  }
};

int main() {
  Solution solute;
  std::string beginWord = "hit", endWord = "cog";

  std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  auto res = solute.ladderLength1(beginWord, endWord, wordList);
  std::cout << res << std::endl;
  return 0;
}
