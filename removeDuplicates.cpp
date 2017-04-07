/*  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *  Do not allocate extra space for another array, you must do this in place with constant memory. 
 *
 *  For example,  
 *    Given input array nums = [1,1,2],
 *    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
 *    It doesn't matter what you leave beyond the new length. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0) return 0;
    int res = 1;
    int n = nums.at(0);
    auto b = nums.begin() + 1, e = nums.end();
    while (b != e) {
      if (n != *b) {
        res++;
        n = *b++;
      } else {
        nums.erase(b);
        e = nums.end();
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
