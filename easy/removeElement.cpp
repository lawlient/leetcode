/*  Given an array and a value, remove all instances of that value in place and return the new length.
 *  Do not allocate extra space for another array, you must do this in place with constant memory.
 *  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *  
 *  Example:
 *    Given input array nums = [3,2,2,3], val = 3
 *    Your function should return length = 2, with the first two elements of nums being 2.
 *  
*/

/*  template <class ForwardIterator, class T>
 *  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val)
 *  {
 *    ForwardIterator result = first;
 *    while (first!=last) {
 *      if (!(*first == val)) {
 *        *result = *first;
 *        ++result;
 *      }
 *      ++first;
 *    }
 *    return result;
 *  }
 *
 *  template <class ForwardIterator, class UnaryPredicate>
 *  ForwardIterator remove_if (ForwardIterator first, ForwardIterator last,
 *                             UnaryPredicate pred) {
 *    ForwardIterator result = first;
 *    while (first!=last) {
 *      if (!pred(*first)) {
 *        *result = *first;
 *        ++result;
 *      }
 *      ++first;
 *    }
 *    return result;
 *  }
 *
 *
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    return std::remove(nums.begin(), nums.end(), val) - nums.begin();
    // return std::remove_if(nums.begin(), nums.end(), [val](int n){ return val == n; }) - nums.begin();
  }
};

int main() {
  std::vector<int> input{3, 3, 2, 2};
  std::cout << Solution().removeElement(input, 3) << std::endl;
  return 0;
}
