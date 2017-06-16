/*  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *  push(x) -- Push element x onto stack.
 *  pop() -- Removes the element on top of the stack.
 *  top() -- Get the top element.
 *  getMin() -- Retrieve the minimum element in the stack.
 *
 *  Example:
 *
 *  MinStack minStack = new MinStack();
 *  minStack.push(-2);
 *  minStack.push(0);
 *  minStack.push(-3);
 *  minStack.getMin();   --> Returns -3.
 *  minStack.pop();
 *  minStack.top();      --> Returns 0.
 *  minStack.getMin();   --> Returns -2.
 *  
 *
 *
*/

/*  
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
#include <set>
#include <queue>
#include <string>
#include <list>

class MinStack {
  std::stack<int> s;
  std::stack<int> m;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
       s.push(x);
       if (m.empty() || x <= m.top()) m.push(x);
    }
    
    void pop() {
      if (s.top() == m.top()) m.pop();
      s.pop();
    }
    
    int top() {
      return s.top();
    }
    
    int getMin() {
      return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  std::cout << minStack.getMin() << std::endl;   // --> Returns -3.
  minStack.pop();
  std::cout << minStack.top() << std::endl;      // --> Returns 0.
  std::cout << minStack.getMin() << std::endl;   // --> Returns -2.
}
