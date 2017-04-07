/*  Given two words (beginWord and endWord), and a Listionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
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

using namespace std;
// BFS
class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordDict) {
  // int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> &wordDict) {
   unordered_set<string> head, tail, *phead, *ptail;
   head.insert(beginWord);
   tail.insert(endWord);
   int dist = 2;
   while (!head.empty() && !tail.empty()) {
     if (head.size() < tail.size()) {
       phead = &head;
       ptail = &tail;
     }
     else {
       phead = &tail; 
       ptail = &head;
     }
     unordered_set<string> temp; 
     for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
       string word = *itr;
       wordDict.erase(std::find(wordDict.begin(), wordDict.end(), word));
       for (int p = 0; p < (int)word.length(); p++) {
         char letter = word[p];
         for (int k = 0; k < 26; k++) {
           word[p] = 'a' + k;
           if (ptail -> find(word) != ptail -> end())
             return dist;
           if (std::find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
             temp.insert(word);
             wordDict.erase(std::find(wordDict.begin(), wordDict.end(), word));
           }
         }
         word[p] = letter;
       }
     }
     dist++;
     swap(*phead, temp);
   }
   return 0; 
  }
};

int main() {
  Solution solute;
  std::string beginWord = "hit", endWord = "cog";
  // std::unordered_set<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  auto res = solute.ladderLength(beginWord, endWord, wordList);
  std::cout << res << "\n";
  return 0;
}
