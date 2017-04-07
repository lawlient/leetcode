/*  Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 *  Your algorithm's runtime complexity must be in the order of O(log n).
 *  If the target is not found in the array, return [-1, -1].
 *
 *  For example,
 *    Given [5, 7, 7, 8, 8, 10] and target value 8,
 *    return [3, 4]. 
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
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::vector<int> ret(2, -1);
    if (!n) return ret;
    int i = 0, j = n - 1;
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (nums[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (nums[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n - 1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (nums[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
  }
};

int main() {
  std::vector<int> param{5, 7, 7, 8, 8, 10};
  Solution solute;
  auto res = solute.searchRange(param, 8);
  std::cout << res.at(0) << ", " << res.at(1) << std::endl;
  return 0;
}
