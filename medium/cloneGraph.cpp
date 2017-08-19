/*  Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *  OJ's undirected graph serialization:
 *
 *  Nodes are labeled uniquely.
 *  We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 *  
 *  As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *  
 *  The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *  
 *      First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 *      Second node is labeled as 1. Connect node 1 to node 2.
 *      Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 *  
 *  Visually, the graph looks like the following:
 *  
 *         1
 *        / \
 *       /   \
 *      0 --- 2
 *           / \
 *           \_/
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
