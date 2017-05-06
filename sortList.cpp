/*  Sort a linked list in O(n log n) time using constant space complexity.
 *
 *
*/

/*  merge sort
 *  
 *  
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
  ListNode *merge(ListNode *h1, ListNode *h2) {
    auto H = new ListNode(INT_MIN);
    auto c = H;
    while (h1 && h2) {
      if (h1->val < h2->val) {
        c->next = h1;
        h1 = h1->next;
      } else {
        c->next = h2;
        h2 = h2->next;
      }
      c = c->next;
    }
    if (h1) c->next = h1;
    if (h2) c->next = h2;
    return H->next;
  }
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    auto slow = head;
    auto high = head->next->next;
    while (high && high->next) {
      slow = slow->next;
      high = high->next->next;
    }
    auto later = sortList(slow->next);
    slow->next = NULL;
    return merge(sortList(head), later);
  }
};

int main() {
  Solution solute;
  ListNode node1(3);
  ListNode node2(4);
  node2.next = &node1;
  auto res = solute.sortList(&node2);
  while (res) {
    std::cout << res->val << std::endl;
    res = res->next;
  }
  return 0;
}
