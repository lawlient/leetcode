/*  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *  Valid operators are +, -, *, /. Each operand may be an integer or another expression. 
 *
 *
*/

/* stack
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> s;
    for (const auto &t : tokens) {
      if (t == "+") {
        auto m = s.top(); s.pop();
        auto n = s.top(); s.pop();
        s.push(n + m);
      } else if (t == "-") {
        auto m = s.top(); s.pop();
        auto n = s.top(); s.pop();
        s.push(n - m);
      } else if (t == "*") {
        auto m = s.top(); s.pop();
        auto n = s.top(); s.pop();
        s.push(n * m);
      } else if (t == "/") {
        auto m = s.top(); s.pop();
        auto n = s.top(); s.pop();
        s.push(n / m);
      } else {
        int n = std::stoi(t);
        s.push(n);
      }
    }
    return s.top();
  }
};

int main() {
  Solution solute;
  // std::vector<std::string> input{"2", "1", "+", "3", "*"};
  std::vector<std::string> input{"4", "13", "5", "/", "+"};
  auto res  = solute.evalRPN(input);
  std::cout << res << std::endl;
  return 0;
}
