/*  Given a sorted array,
 *  remove the duplicates in place such that each element appear only once and return the new length.
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

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    for (auto i = nums.begin(); i < nums.end(); i++) {
      for (auto j = i + 1; j < nums.end();) {
        if (*i != *j)
          break;
        nums.erase(j);
      }
    }
    return nums.size();
  }
};

int main() {
  return 0;
}
