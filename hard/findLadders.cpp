/*  Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 *
 *  Only one letter can be changed at a time
 *  Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *
 *  For example,
 *  
 *  Given:
 *  beginWord = "hit"
 *  endWord = "cog"
 *  wordList = ["hot","dot","dog","lot","log","cog"]
 *  
 *  Return
 *  
 *    [
 *      ["hit","hot","dot","dog","cog"],
 *      ["hit","hot","lot","log","cog"]
 *    ]
 *  
 *  Note:
 *  
 *      Return an empty list if there is no such transformation sequence.
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
  
  void help(std::vector<std::vector<std::string>> &res, std::vector<std::string> one,
            std::string beginWord, std::string endWord, std::set<std::string> wordList) {
    std::set<std::string> nextBegin;
    for (const auto &w : wordList) {
      if (isTransformation(w, beginWord)) {
        nextBegin.insert(w);
        wordList.erase(w);
      }
    }
    if (nextBegin.empty()) return;
    if (nextBegin.count(endWord)) {
      one.push_back(endWord);
      res.push_back(one);
      return;
    }
    for (const auto &w : nextBegin) {
      one.push_back(w);
      help(res, one, w, endWord, wordList);
      one.pop_back();
    }
  }
public:
  std::vector<std::vector<std::string>> ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    std::vector<std::vector<std::string>> res;
    if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return res;
    std::vector<std::string> one{beginWord};
    std::set<std::string> words(wordList.begin(), wordList.end());
    help(res, one, beginWord, endWord, words);
    return res;
  }

  std::vector<std::vector<std::string>> ladderLength2(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    std::vector<std::vector<std::string>> res;
    std::set<std::string> lists(wordList.begin(), wordList.end());
    if (lists.count(endWord) == 0)
      return res;
    std::vector<std::string> one{beginWord};
    res.push_back(one);
    std::set<std::string> nextBegin;
    while (!res.empty()) {
      for (const auto &w : lists) {
        if (isTransformation(w, beginWord)) {
          nextBegin.insert(w);
          lists.erase(w);
        }
      }
      if (nextBegin.empty()) break;
      if (nextBegin.count(endWord)) {
        for (auto &r : res) {
          r.push_back(endWord);
        }
        return res;
      }
      for (const auto &b : nextBegin) {
        one.push_back(b);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
