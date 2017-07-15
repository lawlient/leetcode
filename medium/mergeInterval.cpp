/*  Given a collection of intervals, merge all overlapping intervals.
 *
 *  For example,
 *  Given [1,3],[2,6],[8,10],[15,18],
 *  return [1,6],[8,10],[15,18]. 
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
  std::vector<Interval> merge(std::vector<Interval> &intervals) {
    if (intervals.empty()) return intervals;
    auto compare = [](const Interval &l, const Interval &r) { return l.start < r.start; };
    std::sort(intervals.begin(), intervals.end(), compare);
    for (auto b = intervals.begin(); b < intervals.end()-1;) {
      if (b->end >= (b+1)->start) {
        b->end = std::max(b->end, (b+1)->end);
        intervals.erase(b+1);
      } else
        b++;
    }
    return intervals;
  }

  std::vector<Interval> merge2(std::vector<Interval> &intervals) {
    std::vector<Interval> res;
    if (intervals.size() == 0) return res;
    std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
    res.push_back(intervals[0]);
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (res.back().end < intervals[i].start)
        res.push_back(intervals[i]);
      else 
        res.back().end = std::max(res.back().end, intervals[i].end);
    }
    return res;
  }
};

int main() {
  Solution solute;
  Interval i1(1, 3);
  Interval i2(2, 6);
  Interval i3(8, 10);
  Interval i4(15, 18);
  std::vector<Interval> input{i1, i2, i3, i4};
  auto res = solute.merge(input);
  for (auto i : res) {
    std::cout << "[" << i.start << ", " << i.end << "]" << '\n';
  }
  return 0;
}
