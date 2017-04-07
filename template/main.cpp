/*  Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *  Only one letter can be changed at a time.
 *  Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *  
 *  For example,
 *  Given:
 *  beginWord = "hit"
 *  endWord = "cog"
 *  wordList = ["hot","dot","dog","lot","log","cog"]
 *  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *  return its length 5.
 *  Note:
 *
 *  Return 0 if there is no such transformation sequence.
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 *  You may assume no duplicates in the word list.
 *  You may assume beginWord and endWord are non-empty and are not the same.
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

// BFS
class Solution {
public:
  int ladderLength1(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    std::unordered_set<std::string> head, tail;
    head.insert(beginWord); tail.insert(endWord);
    int dist = 2;
    while (!head.empty() && !tail.empty()) {
      auto &p = head, &q = tail;
      if (head.size() >= tail.size()) 
        std::swap(p, q);
      std::unordered_set<std::string> tmp;
      for (auto word : p) {
        auto findw = std::find(wordList.begin(), wordList.end(), word);
        if (findw != wordList.end()) {
          wordList.erase(findw);
        }
        for (auto &c : word) {
          char ch = c;
          for (int k = 0; k < 26; k++) {
            c = 'a' + k;
            if (q.find(word) != q.end()) 
              return dist;
            auto findw = std::find(wordList.begin(), wordList.end(), word);
            if (findw != wordList.end()) {
              tmp.insert(word);
              wordList.erase(findw);
            }
          }
          c = ch;
        }
      }
      dist++;
      std::swap(p, tmp);
    }
    return 0;
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
