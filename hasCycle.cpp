/*  Given a linked list, determine if it has a cycle in it.
 *  Follow up:
 *  Can you solve it without using extra space? 
 * 
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <queue>
#include <math.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// two pointers
// the one forward step by step
// the other forward two stepes every time
// if there is a cycle in list
// two pointers will encounter.
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) return false;
    auto p = head, q = head;
    while (q->next && q->next->next) {
      p = p->next;
      q = q->next->next;
      if (q == p) return true;
    }
    return false;
  }
};

int main() {
  Solution solute;
  ListNode head(3);
  auto res = solute.hasCycle(&head);
  std::cout << res << std::endl;
  return 0;
}
