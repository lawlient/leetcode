/*  
 *  
 *  
 *  
 *  
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

struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
  std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
public:
  // DFS
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;
    if (mp.find(node) == mp.end()) {
        mp[node] = new UndirectedGraphNode(node->label);
        for (auto neigh : node->neighbors) 
          mp[node]->neighbors.push_back(cloneGraph(neigh));
    }
    return mp[node];
  }

  //BFS
  UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
    if (!node) return NULL;
    auto copy = new UndirectedGraphNode(node->label);
    mp[node] = copy;
    std::queue<UndirectedGraphNode *> visit;
    visit.push(node);
    while (!visit.empty()) {
      auto N = visit.front(); visit.pop();
      for (auto n : N->neighbors) {
        if (mp.find(n) == mp.end()) {
          auto nCopy = new UndirectedGraphNode(n->label);
          mp[n] = nCopy;
          visit.push(n);
        }
        mp[N]->neighbors.push_back(mp[n]);
      }
    }
    return copy;
  }
};

int main() {
  Solution solute;
  return 0;
}
