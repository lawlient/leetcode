/* Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto head = ListNode(0);
    auto p = l1, q = l2;
    auto r = &head;
    while (p && q) {
      auto &move = p->val < q->val ? p : q;
      r = r->next = move;
      move = move->next;
    }
    r->next = p ? p : q;
    return head.next;
  }
};

int main() {
  return 0;
}
