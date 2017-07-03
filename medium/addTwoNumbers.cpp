/*  You are given two non-empty linked lists representing two non-negative integers. 
 *  The digits are stored in reverse order and each of their nodes contain a single digit. 
 *  Add the two numbers and return it as a linked list.  
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.  
 *
 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto p = l1;
    auto q = l2;
    auto res = ListNode(0);
    auto r = &res;
    int c = 0;
    while (p || q) {
      if (p) {
        c += p->val;
        p = p->next;
      }
      if (q) {
        c += q->val;
        q = q->next;
      }
      r = r->next = new ListNode(c%10);
      c = c / 10;
    }
    if (c) r->next = new ListNode(c);
    return res.next;
  }
};

int main() {
  auto l1 = ListNode(1);
  auto l2 = ListNode(3);
  std::cout << Solution().addTwoNumbers(&l1, &l2)->val << std::endl;
  return 0;
}
