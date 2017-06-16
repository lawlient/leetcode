/*  Given an array of size n, find the majority element. 
 *  The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 *  You may assume that the array is non-empty and the majority element always exist in the array.
 *  
 *  
 *
 *
*/

/*  
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
#include <set>
#include <queue>
#include <string>
#include <list>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    std::map<int, unsigned> c;
    for (auto &i : nums)
      c[i]++;
    auto size = nums.size();
    auto comp = [size](std::pair<int, unsigned> e) {
      return e.second >= size/2 + 1;
    };
    auto pos = std::find_if(c.begin(), c.end(), comp);
    return pos->first;
  }
};
