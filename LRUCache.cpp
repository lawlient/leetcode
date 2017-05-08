/*  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 *  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 *  put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 *  Follow up:
 *    Could you do both operations in O(1) time complexity?
 *    
 *  Example:
 *    LRUCache cache = new LRUCache( 2 ** capacity ** );
 *
 *    cache.put(1, 1);
 *    cache.put(2, 2);
 *    cache.get(1);       // returns 1
 *    cache.put(3, 3);    // evicts key 2
 *    cache.get(2);       // returns -1 (not found)
 *    cache.put(4, 4);    // evicts key 1
 *    cache.get(1);       // returns -1 (not found)
 *    cache.get(3);       // returns 3
 *    cache.get(4);       // returns 4
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

class LRUCache {
  size_t _capacity;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> _map;
  std::list<std::pair<int, int>> _list;
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
      auto found = _map.find(key);
      if (found == _map.end()) {
        return -1;
      }
      _list.splice(_list.begin(), _list, found->second);
      return found->second->second;
    }
    
    void put(int key, int value) {
      auto found = _map.find(key);
      if (found != _map.end()) {
        _list.splice(_list.begin(), _list, found->second);
        found->second->second = value;
        return;
      }
      if (_map.size() == _capacity) {
        int del = _list.back().first;
        _list.pop_back();
        _map.erase(del);
      }
      _list.emplace_front(key, value);
      _map[key] = _list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class Solution {
};

int main() {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2); 
  cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.get(1);       // returns -1 (not found)
  cache.get(3);       // returns 3
  cache.get(4);       // returns 4
  return 0;
}
