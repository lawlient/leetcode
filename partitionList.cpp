/*  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *  You should preserve the original relative order of the nodes in each of the two partitions.
 *  
 *  For example,
 *  Given 1->4->3->2->5->2 and x = 3,
 *  return 1->2->2->4->3->5. 
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
#include <map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    auto p = &node1;
    auto q = &node2;
    while (head) {
      if (head->val < x) {
        p->next = head;
        p = p->next;
      } else {
        q->next = head;
        q = q->next;
      }
      head = head->next;
    }
    q->next = nullptr;
    p->next = node2.next;
    return node1.next;
  }
};

int main() {
  Solution solute;
  ListNode *p = nullptr;
  auto res = solute.partition(p, 3);
  std::cout << res->val << "\n";
  return 0;
}
