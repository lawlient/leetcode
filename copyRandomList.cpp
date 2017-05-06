/*  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *  Return a deep copy of the list. 
 *
*/

/*  hash table. 
 *  two maps record node's position;
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
#include <unordered_set>
#include <map>
#include <queue>

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return head;
    std::map<RandomListNode *, unsigned> oIndex;
    std::map<unsigned, RandomListNode *> nIndex;

    RandomListNode *new_head = new RandomListNode(head->label);
    unsigned i = 0;
    nIndex.insert(std::make_pair(i, new_head));
    oIndex.insert(std::make_pair(head, i++));
    auto p = head->next;
    auto h = new_head;
    while (p) {
      RandomListNode *node = new RandomListNode(p->label);
      nIndex.insert(std::make_pair(i, node));
      oIndex.insert(std::make_pair(p, i++));
      h = h->next = node;
      p = p->next;
    }

    p = head;
    h = new_head;
    while (p) {
      if (p->random != NULL) {
        auto j = oIndex.find(p->random);
        h->random = nIndex.find(j->second)->second;
      }
      p = p->next;
      h = h->next;
    }
    return new_head;
  }
};

int main() {
  Solution solute;
  RandomListNode head(1);
  auto res = solute.copyRandomList(&head);
  std::cout << res->label << "\n";
  return 0;
}
