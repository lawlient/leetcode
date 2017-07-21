/*  Given a sorted linked list, delete all nodes that have duplicate numbers,
 *  leaving only distinct numbers from the original list.
 *
 *  For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3. 
 *  
 *  
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    auto node = ListNode(0);
    auto r = &node;
    auto h = head;
    while (h) {
      auto n = h->next;
      if (!n) {
        r->next = h;
        break;
      }
      if (n->val != h->val) {
        r = r->next = h;
        h = h->next;
        r->next = nullptr;
        continue;
      }
      while (n && n->val == h->val) n = n->next;
      h = n;
    }
    return node.next;
  }

  ListNode *deleteDuplicates2(ListNode *head) {
    ListNode newH(0);
    auto p = &newH;
    while (head) {
      if (head->next == nullptr) {
        p = p->next = head;
        break;
      }
      if (head->val != head->next->val) {
        p = p->next = head;
        head = head->next;
        continue;
      }
      int v = head->val;
      while (head && head->val == v)
        head = head->next;
    }
    p->next = nullptr;
    return newH.next;
  }
};

int main() {
  ListNode n5(3);
  ListNode n4(2);
  n4.next = &n5;
  ListNode n3(1);
  n3.next = &n4;
  ListNode n2(1);
  n2.next = &n3;
  ListNode n1(1);
  n1.next = &n2;
  Solution solute;
  auto res = solute.deleteDuplicates(&n3);
  for (auto n = res; n; n = n->next) {
    std::cout << n->val << "\t";
  }
  std::cout << "\n";
  return 0;
}
