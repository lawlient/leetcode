/*  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *  You are given a target value to search. If found in the array return its index, otherwise return -1.
 *  You may assume no duplicate exists in the array.
 *  
*/

#include <iostream>
#include <climits>
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
  int search(std::vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] > nums[high]) low = mid + 1;
      else high = mid;
    }
    int rotate = low;
    low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int realPos = (mid + rotate) % nums.size();
      if( nums[realPos] == target) return realPos;
      else if (nums[realPos] < target) low = mid + 1;
      else high = mid - 1;
    }
    return -1;
  }
};

int main() {
  std::vector<int> param{4, 5, 6, 7, 0, 1, 2};
  Solution solute;
  auto res = solute.search(param, 6);
  std::cout << res << std::endl;
  return 0;
}
