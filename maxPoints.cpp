/*  Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *  
 *
 *
*/

/*  three poins are on the same line if each two of them has the same slope.
 *  but slope by division is not precise
 *  so, we use pair<int, int> divided by gcd as the key, not slope by division.
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

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(std::vector<Point> &points) {
    auto size = points.size();
    if(size < 2) return size;
    int result = 0;
    for (unsigned i = 0; i < size; i++) {
      std::map<std::pair<int, int>, int> lines;
      int localmax = 0, overlap = 0, vertical = 0;
            
      for (unsigned j = i+1; j < size; j++) {
        if (points[j].x == points[i].x && points[j].y == points[i].y) {
          overlap++;
          continue;
        } else if (points[j].x == points[i].x) vertical++;
        else {
          int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
          int gcd = std::__gcd(a, b);
          a /= gcd;
          b /= gcd;
          lines[std::make_pair(a, b)]++;
          localmax = std::max(lines[std::make_pair(a, b)], localmax);
        }
        localmax = std::max(vertical, localmax);
      }
      result = std::max(result, localmax+overlap+1);
    }
    return result;
  }
};

int main() {
  Solution solute;
  Point p1(0, 0);
  Point p2(94911151, 94911150);
  Point p3(94911152, 94911151);
  Point p5(3, 1);
  std::vector<Point> input{p1, p2, p3};
  auto res = solute.maxPoints(input);
  std::cout << res << std::endl;
  return 0;
}
