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
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->val > l2->val) std::swap(l1, l2);
    auto p = l1, q = l2, tmp = q;
    while (p->next && q) {
      if (p->next->val > q->val) {
        tmp = q;
        q = q->next;
        tmp->next = p->next;
        p->next = tmp;
      } else {
        p = p->next;
      }
    }
    if (q) p->next = q;
    return l1;
  }
};

int main() {
  return 0;
}
