/*  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *  For example,
 *  Given [100, 4, 200, 1, 3, 2],
 *  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.  
 *  Your algorithm should run in O(n) complexity. 
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
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    if (nums.empty()) return 0;
    std::sort(nums.begin(), nums.end());
    int max = 0, l = 1;
    for (int i = 0; i < nums.size()-1; i++) {
      if (nums[i] + 1 == nums[i+1])
        l++;
      else if (nums[i] != nums[i+1]) {
        max = std::max(max, l);
        l = 1;
      }
    }
    max = std::max(max, l);
    return max;
  }
};

int main() {
  Solution solute;
  std::vector<int> input{};
    std::sort(input.begin(), input.end());

  auto res = solute.longestConsecutive(input);
  std::cout << res << "\n";
  return 0;
}
