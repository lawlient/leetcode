/*  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return NULL;
    if (head->next == nullptr) 
      return new TreeNode(head->val);
    auto p = head;
    int size = 1;
    while (p->next) { size++; p = p->next; }
    int preNode = size / 2 - 1;
    p = head;
    while (preNode--) p = p->next;
    auto cur = p->next;
    p->next = NULL; p = cur->next;
    auto node = new TreeNode(cur->val);
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(p);
    return node;
  }
};

int main() {
  Solution solute;
  ListNode input1(1), input2(2), input3(3), input4(4), input5(5);
  input1.next = &input2;
  input2.next = &input3;
  input3.next = &input4;
  input4.next = &input5;
  auto res = solute.sortedListToBST(&input1);
  std::cout << res->val << "\n";
  return 0;
}
