#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
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
