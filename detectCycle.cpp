/*  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *  Note: Do not modify the linked list.
 *  Follow up:
 *  Can you solve it without using extra space? 
 *  
*/

/*  my solution is like this: using two pointers, one of them one step at a time.Another pointer each take two steps. 
 *  Suppose the first meet at step k,the length of the Cycle is r. so..2k-k=nr,k=nr
 *  Now, the distance between the start node of list and the start node of cycle is s. 
 *  the distance between the start of list and the first meeting node is k(the pointer which wake one step at a time waked k steps).
 *  the distance between the start node of cycle and the first meeting node is m, so...s=k-m,s=nr-m=(n-1)r+(r-m),here we takes n = 1.
 *  So, using one pointer start from the start node of list, another pointer start from the first meeting node, 
 *  all of them wake one step at a time, the first time they meeting each other is the start of the cycle.
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
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return NULL;
    auto p = head, q = head;
    bool hasCycle = false;
    while (p && q) {
      p = p->next;
      if (!q->next) return NULL;
      q = q->next->next;
      if (p == q) {
        hasCycle = true;
        break;
      }
    }
    if (!hasCycle) return NULL;
    q = head;
    while (q != p) {
      p = p->next;
      q = q->next;
    }
    return q;
  }
};

int main() {
  Solution solute;
  ListNode head(3);
  ListNode node1(4);
  head.next = &node1;
  node1.next = &node1;
  auto res = solute.detectCycle(&head);
  if (res)
    std::cout << res->val << std::endl;
  return 0;
}
