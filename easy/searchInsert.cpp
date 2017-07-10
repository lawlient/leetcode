/*  Given a sorted array and a target value, return the index if the target is found.
 *  If not, return the index where it would be if it were inserted in order.
 *
 *  You may assume no duplicates in the array.
 *
 *  Here are few examples.
 *    [1,3,5,6], 5 → 2
 *    [1,3,5,6], 2 → 1
 *    [1,3,5,6], 7 → 4
 *    [1,3,5,6], 0 → 0 
 *  
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int p = 0, q = nums.size() - 1;
    while (p <= q) {
      int m = p + (q - p) / 2;
      nums[m] < target ? p = m + 1 : q = m - 1;
    }
    return p;
  }
};

int main() {
  return 0;
}
