/*  Given a linked list, swap every two adjacent nodes and return its head.
 *  For example,
 *    Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *  Your algorithm should use only constant space.
 *  You may not modify the values in the list, only nodes itself can be changed. 
*/

/*  we think two nodes every loop
 *
 *  pre == false : first node just append at result
 *
 *  pre == true  : second node insert from first node
 *                 update iterator for next loop
 *
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    auto res = ListNode(0);
    auto p = head, r = &res;
    bool pre = false;
    while (p) {
      auto tmp = p->next;
      if (pre) {
        p->next = r->next;
        r->next = p;
        r = r->next->next;
      } else {
        p->next = NULL;
        r->next = p;
      }
      pre = !pre;
      p = tmp;
    }
    return res.next;
  }
};

int main() {
  return 0;
}
