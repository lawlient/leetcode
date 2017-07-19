/*  Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 *  For example:
 *  Given 1->2->3->4->5->NULL and k = 2,
 *  return 4->5->1->2->3->NULL.
 *  
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return head;
    size_t length = 1;
    auto *p = head;
    while (p->next) {
      length++;
      p = p->next;
    }
    p->next = head;
    k = length - k%length;
    while (k-- > 0)
      p = p->next;
    head = p->next;
    p->next = NULL;
    return head;
  }
};

int main() {
  Solution solute;
  ListNode l1(1);
  auto res = solute.rotateRight(&l1, 0);
  std::cout << res->val << std::endl;
  return 0;
}
