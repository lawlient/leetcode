/*  Given a list of non negative integers, arrange them such that they form the largest number.  
 *  For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.  
 *
 *  Note: The result may be very large, so you need to return a string instead of an integer.
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
#include <queue>
#include <list>


class Solution {
public:
  std::string largestNumber(std::vector<int> &nums) {
    std::vector<std::string> ns;
    for (auto &i : nums) {
      ns.push_back(std::to_string(i));
    }
    auto cmp = [](std::string &a, std::string &b) { return a + b > b + a; };
    std::sort(ns.begin(), ns.end(), cmp);
    std::string res{};
    for (auto &s : ns) {
      res += s;
    }
    while (res[0] == '0' && res.length() > 1)
      res.erase(0, 1);
    return res;
  }
};

int main() {
  std::vector<int> input{3, 30, 34, 5, 9};
  std::cout << Solution().largestNumber(input) << std::endl;
}
