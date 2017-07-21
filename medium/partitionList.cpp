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
    auto node1 = ListNode(0); auto r1 = &node1;
    auto node2 = ListNode(0); auto r2 = &node2;
    auto h = head;
    while (h) {
      if (x > h->val) {
        r1 = r1->next = h;
      } else {
        r2 = r2->next = h;
      }
      h = h->next;
    }
    r1->next = node2.next;
    r2->next = nullptr;
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
