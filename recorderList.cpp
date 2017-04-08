/*  Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln,
 *
 *  reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 *  You must do this in-place without altering the nodes' values.
 *  
 *  For example,
 *  Given {1,2,3,4}, reorder it to {1,4,2,3}. 
 *  
*/

/*  three steps:
 *  1. find the middle node
 *  2. reverse the latter half list
 *  3. merge two half lists
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
  void recorderList(ListNode *head) {
    if (!head) return;
    int n = 0;
    auto p = head;
    while (p) { n++; p = p->next; }

    p = head;
    for (int i = n / 2; i > 0; i--)
      p = p->next;

    auto q = p->next;
    p->next = NULL;
    ListNode tmp(0);
    while (q) {
      p = q->next;
      q->next = tmp.next;
      tmp.next = q;
      q = p;
    }

    p = head;
    q = tmp.next;
    while (q) {
      tmp.next = q->next;
      q->next = p->next;
      p->next = q;
      p = q->next;
      q = tmp.next;
    }
  }
};

int main() {
  Solution solute;
  ListNode head(1);
  ListNode node1(2);
  ListNode node2(3);
  ListNode node3(4);
  head.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  solute.recorderList(&head);
  auto p = &head;
  while (p) {
    std::cout << p->val << '\t';
    p = p->next;
  }
  std::cout << "\n";
  // std::cout << res << std::endl;
  return 0;
}
