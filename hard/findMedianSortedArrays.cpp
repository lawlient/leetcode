/*  There are two sorted arrays nums1 and nums2 of size m and n respectively.  
 *  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).  
 *
 *  Example 1: 
 *    nums1 = [1, 3]
 *    nums2 = [2] 
 *    The median is 2.0 
 *  
 *  Example 2: 
 *    nums1 = [1, 2]
 *    nums2 = [3, 4] 
 *    The median is (2 + 3)/2 = 2.5
 *
*/


/*  the key to success is find k'th number
 *  see quickSort
 *  partition : x, left < x , right > x
 *     if k'th < x 
 *     then find k'th in left 
 *     else find (k-left) in right
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
  // find v[b..e] kth number
  int getKNumber(std::vector<int> &v, int b, int e, int k) {
    int i = b;
    for (int j = i+1; j <= e; j++) {
      if (v[j] <= v[b]) {
        std::swap(v[++i], v[j]);
      }
    }
    std::swap(v[b], v[i]);

    if (i - b + 1 < k)
      return getKNumber(v, i+1, e, k-i+b-1);
    else if (i - b + 1 > k)
      return getKNumber(v, b, i-1, k);
    else 
      return v[i];
  }
public:
  double findMedianSortedArraysNew(std::vector<int> &nums1, std::vector<int> &nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    auto size = nums1.size();
    int l = (size + 1) >> 1;
    int r = (size + 2) >> 1;
    return (getKNumber(nums1, 0, size - 1, l) + getKNumber(nums1, 0, size - 1, r)) / 2.0;
  }
};

int main() {
  Solution solute;
  std::vector<int> a{1, 3};
  std::vector<int> b{2, 4};
  std::cout << solute.findMedianSortedArraysNew(a, b) << std::endl;
  return 0;
}
