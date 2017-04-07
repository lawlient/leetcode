#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
  int i = 0, j = 0;
  for (auto first = nums.begin(); first != nums.end(); ++first) {
    if (*first < target) {
      auto second = find(first + 1, nums.end(), target - *first);
      if (second != nums.end()) {
        i = first - nums.begin();
        j = second - nums.begin();
        break;
      }
    }
  }
  return vector<int>{i, j};
}
*/

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> res;
  for (auto b = nums.begin(), e = nums.end();
       b != e; ++b) {
    auto second = find(b + 1, e, target - *b);
    if (second != e) {
      res.push_back(b - nums.begin());
      res.push_back(second - nums.begin());
      break;
    }
  }
  return res;
}

int main() {
  vector<int> a{3, 2, 4};
  int target = 6;
  auto res = twoSum(a, target);
  for (auto itr : res) {
    std::cout << itr << "\t";
  }
  std::cout << std::endl;
  return 0;
}
