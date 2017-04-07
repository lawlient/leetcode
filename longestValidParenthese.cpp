/*  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *  For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
  int longestValidParentheses(std::string s) {
    std::stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') st.push(i);
      else {
        if (!st.empty()) {
          if (s[st.top()] == '(') st.pop();
          else st.push(i);
        } else {
          st.push(i);
        }
      }
    }
    if (st.empty()) return n;
    int longest = 0;
    int a = n, b = 0;
    while (!st.empty()) {
      b = st.top(); st.pop();
      longest = std::max(longest, a - b - 1);
      a = b;
    }
    longest = std::max(longest, a);
    return longest;
  }
};

int main() {
  std::vector<int> param{4, 5, 6, 7, 0, 1, 2};
  Solution solute;
  auto res = solute.longestValidParentheses("()");
  std::cout << res << std::endl;
  return 0;
}
