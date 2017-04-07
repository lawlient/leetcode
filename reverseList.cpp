/*  Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 *  For example:
 *  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *  return 1->4->3->2->5->NULL.
 *
 *  Note:
 *  Given m, n satisfy the following condition:
 *  1 ≤ m ≤ n ≤ length of list. 
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    auto p = head, q = head;
    for (int k = m-2; k > 0; k--) p = p->next;
    for (int k = n-1; k > 0; k--) q = q->next;
    if (m == 1) head = q;
    else {
      auto tmp = p->next;
      p->next = q;
      p = tmp;
    }
      
    while (p != q) {
      auto tmp = p->next;
      p->next = q->next;
      q->next = p;
      p = tmp;
    }
    return head;
  }
};

int main() {
  Solution solute;
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  auto res = solute.reverseBetween(&n1, 1, 5);
  while (res) {
    std::cout << res->val << "\t";
    res = res->next;
  }
  return 0;
}
