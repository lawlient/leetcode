/*  Given a sorted linked list, delete all duplicates such that each element appear only once.
 *  For example,
 *  Given 1->1->2, return 1->2.
 *  Given 1->1->2->3->3, return 1->2->3. 
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
    auto h = head;
    while (h) {
      auto r = h->next;
      while (r && r->val == h->val) r = r->next;
      h = h->next = r;
    }
    return head;
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
