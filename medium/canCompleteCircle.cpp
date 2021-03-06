/*  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 *  You begin the journey with an empty tank at one of the gas stations.
 *  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 
 *
 *  Note:
 *    The solution is guaranteed to be unique. 
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
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int end = 0, start = gas.size() - 1;
    int r = gas[start] - cost[start];
    while (start > end) {
      if (r >= 0) {
        r += gas[end] - cost[end];
        end++;
      } else {
        start--;
        r += gas[start] - cost[start];
      }
    }
    return r >= 0 ? start : -1;
  }
};

int main() {
  Solution solute;
  std::vector<int> gas{5};
  std::vector<int> cost{4};
  auto res = solute.canCompleteCircuit(gas, cost);
  std::cout << "index = " << res << std::endl;
  return 0;
}
