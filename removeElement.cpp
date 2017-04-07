/*  Given an array and a value, remove all instances of that value in place and return the new length.
 *  Do not allocate extra space for another array, you must do this in place with constant memory.
 *  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *  
 *  Example:
 *    Given input array nums = [3,2,2,3], val = 3
 *    Your function should return length = 2, with the first two elements of nums being 2.
 *  
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
  int removeElement(std::vector<int> &nums, int val) {
    auto b = nums.begin(), e = nums.end();
    while (b != e) {
      if (*b == val) {
        nums.erase(b);
        e = nums.end();
      } else {
        b++;
      }
    }
    return nums.size();
  }
};

int main() {
  return 0;
}
