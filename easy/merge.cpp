/*  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 *  Note:
 *  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
 *  additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 *  
 *  
*/


/*  like insert sort, we do it from end to begin
 *
 *
*/

#include <iostream>
#include <climits>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <array>
#include <math.h>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m-1, j = n-1, k = m+n-1;
    while (j >= 0)
      nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
  }
};

int main() {
  Solution solute;
  std::vector<int> input{1, 3, 5, 6, 2, 3};
  std::vector<int> input2{2, 4, 5, 6, 2, 3};
  solute.merge(input, 3, input2, 2);
  for (auto i : input) {
    std::cout << i << "\t";
  }
  std::cout << "\n";
  return 0;
}
