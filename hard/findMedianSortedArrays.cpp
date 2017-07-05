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

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
  int getKth(const std::vector<int> &v1, int start1,
             const std::vector<int> &v2, int start2, int k) {
    int m = v1.size(), n = v2.size();
    int l1 = m - start1, l2 = n - start2;
    if (l1 > l2) return getKth(v2, start2, v1, start1, k);

    if (l1 == 0) return v2[start2 + k - 1];
    if (k == 1) return std::min(v1[start1], v2[start2]);

    int i = std::min(l1, k / 2);
    int j = std::min(l2, k / 2);
    if (v1[start1 + i - 1] > v2[start2 + j - 1]) 
      return getKth(v1, start1, v2, start2 + j, k - j);
    else
      return getKth(v1, start1 + i, v2, start2, k - i);
    return 0;
  }
public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    if (nums1.size() > nums2.size()) std::swap(nums1, nums2);
    int l = (nums1.size() + nums2.size() + 1) >> 1;
    int r = (nums1.size() + nums2.size() + 2) >> 1;
    return (getKth(nums1, 0, nums2, 0, l) + getKth(nums1, 0, nums2, 0, r)) / 2.0;
  }

  double findMedianSortedArrays2(std::vector<int> &nums1, std::vector<int> &nums2) {
    size_t m = nums1.size();
    size_t n = nums2.size();
    if (m > n) { std::swap(m, n); std::swap(nums1, nums2); }
    size_t imin = 0, imax = m, half_length = (m + n + 1) / 2;
    double max_of_left = 0, min_of_rigth = 0;
    while (imin <= imax) {
      size_t i = (imin + imax) / 2;
      size_t j = half_length - i;
      if (i < m && nums1[i] < nums2[j-1]) imin = i + 1;
      else if (i > 0 && nums1[i-1] > nums2[j]) imax = i - 1;
      else {
        if (i == 0) max_of_left = nums2[j-1];
        else if(j == 0) max_of_left = nums1[i-1];
        else max_of_left = std::max(nums1[i-1], nums2[j-1]);

        if ((m + n) % 2 == 1) return max_of_left;

        if (i == m) min_of_rigth = nums2[j];
        else if (j == n) min_of_rigth = nums1[i];
        else min_of_rigth = std::min(nums1[i], nums2[j]);

        return (max_of_left + min_of_rigth) / 2.0;
      }
    }
    return 0;
  }
};

int main() {
  Solution solute;
  std::vector<int> a{1, 3};
  std::vector<int> b{2};
  std::cout << solute.findMedianSortedArrays(a, b) << std::endl;
  return 0;
}
