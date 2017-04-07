/*   Given a linked list, swap every two adjacent nodes and return its head.
 *   For example,
 *     Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *   Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
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
    if (head == nullptr || head->next == nullptr) return head;
    auto new_head = head->next;
    auto p = head, q = head->next;
    p->next = q->next;
    q->next = p;
    auto cur_head = p;
    p = cur_head->next;
    if (p) q = p->next;
    else q = nullptr;
    cur_head->next = nullptr;
    while (p && q) {
      p->next = q->next;
      q->next = p;
      cur_head->next = q;
      cur_head = p;
      p = cur_head->next;
      if (p) q = p->next;
      else q = nullptr;
      cur_head->next = nullptr;
    }
    if (p && q == nullptr) {
      cur_head->next = p;
      p->next = nullptr;
    }
    return new_head;
  }
};

int main() {
  return 0;
}
