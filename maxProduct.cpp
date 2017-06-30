/*  Find the contiguous subarray within an array (containing at least one number) which has the largest product.  
 *  For example, given the array [2,3,-2,4],
 *  the contiguous subarray [2,3] has the largest product = 6. 
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
#include <queue>
#include <list>


class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int m = nums[0];
    int max = m, min = m;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) std::swap(max, min);
      max = std::max(nums[i], nums[i] * max);
      min = std::min(nums[i], nums[i] * min);
      m = std::max(m, max);
    }
    return m;
  }
};

int main() {
  std::vector<int> input{2, 3, -2, 4};
  std::cout << Solution().maxProduct(input) << std::endl;
}
