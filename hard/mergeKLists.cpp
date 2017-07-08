/*  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

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

  struct compare {
    bool operator()(ListNode *l, ListNode *r) {
      return l->val > r->val;
    }
  };
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    // auto compare = [](ListNode *l, ListNode *r) { return l->val > r->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, compare> q;
    for (auto &l : lists)
      if (l) q.push(l);
    if (q.empty()) return NULL;
    auto res = q.top(); q.pop();
    if (res->next) q.push(res->next);
    auto r = res;
    while (!q.empty()) {
      r = r->next = q.top(); q.pop();
      if (r->next) q.push(r->next);
    }
    return res;
  }

  ListNode *mergeKLists2(std::vector<ListNode *> &lists) {
    while (lists.size() > 1) {
      auto l1 = lists.back();
      lists.pop_back();
      auto l2 = lists.back();
      lists.pop_back();
      l1 = mergeTwoLists(l1, l2);
      lists.push_back(l1);
    }
    return lists.at(0);
  }
};

int main() {
  return 0;
}
