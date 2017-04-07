/*  Given a linked list, remove the nth node from the end of list and return its head.
 *  For example,
 *  Given linked list: 1->2->3->4->5, and n = 2.
 *  After removing the second node from the end, the linked list becomes 1->2->3->5.
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto p = head;
    int length = 0;
    while (p) {
      length += 1;
      p = p->next;
    }
    if (length == n) return head->next;
    int i = 0;
    p = head;
    while (i <= length - n) {
      p = p->next;
      i++;
    }
    auto remove = p->next;
    p->next = remove->next;
    return head;
  }
};

int main() {
  Solution solute;
  ListNode l1(1);
  std::cout << solute.removeNthFromEnd(&l1, 2)->val << std::endl;
  return 0;
}
