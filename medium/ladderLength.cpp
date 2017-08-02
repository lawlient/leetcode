/*  Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: 
 *  Only one letter can be changed at a time.
 *  Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *  
 *  For example, 
 *  Given:
 *  beginWord = "hit"
 *  endWord = "cog"
 *  wordList = ["hot","dot","dog","lot","log","cog"]
 *  
 *  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *  return its length 5.
 *  
 *  Note:
 *  
 *      Return 0 if there is no such transformation sequence.
 *      All words have the same length.
 *      All words contain only lowercase alphabetic characters.
 *      You may assume no duplicates in the word list.
 *      You may assume beginWord and endWord are non-empty and are not the same.
 *  
 *
*/

/* 
 *  
 *  
 *  
*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <list>

class Solution {
  bool isTransformation(const std::string &a, const std::string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        if (diff > 1)
          return false;
        else 
          diff++;
      }
    }
    return diff == 1;
  }
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    int step = 1;
    auto endPos = std::find(wordList.begin(), wordList.end(), endWord);
    if (endPos == wordList.end())
      return false;

    std::vector<std::string> endSet{beginWord};
    while (!endSet.empty() && !wordList.empty()) {
      step++;
      std::vector<std::string> tmp; // next beginWord
      for (const auto &b : endSet) {
        for (int j = 0; j < wordList.size(); j++) {
          if (isTransformation(b, wordList[j])) {
            if (wordList[j] == endWord)
              return step;
            tmp.push_back(wordList[j]);
            wordList.erase(wordList.begin()+j);
            j--;
          }
        }
      }
      std::swap(tmp, endSet);
    }
    return 0;
  }
};

int main() {
  return 0;
}
