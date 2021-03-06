/*  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *  You may assume that the intervals were initially sorted according to their start times.
 *  
 *  Example 1:
 *  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *  
 *  Example 2:
 *  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
 *  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    auto compare = [](const Interval &l, const Interval &r) { return l.start < r.start; };
    std::sort(intervals.begin(), intervals.end(), compare);
    for (auto b = intervals.begin(); b < intervals.end() - 1;) {
      if (b->end >= (b+1)->start) {
        b->end = std::max(b->end, (b+1)->end);
        intervals.erase(b+1);
      } else 
        b++;
    }
    return intervals;
  }
};

int main() {
  Solution solute;
  std::vector<Interval> input;
  auto res = solute.insert(input, Interval(2, 5));
  // std::cout << res << "\n";
  return 0;
}
