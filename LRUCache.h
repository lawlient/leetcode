// Source: http://www.cs.uml.edu/~jlu1/doc/codes/lruCache.html

/*
Question: Implement LRU cache algorithm
Implement the LRU cache algorithm with the following interface:

T get(K key);
void put(K key, T data);


What is LRU?
Least Recently Used (LRU) is a family of caching algorithms,
which discards the least recently used items first.

This algorithm requires keeping track of when the item was used,
which is expensive if one wants to make sure the algorithm always
discards the least recently used item. General implementations of
this technique require keeping "age bits" for cache-lines and
track the "Least Recently Used" cache-line based on age-bits.

Data Structure
The key data structure of the algorithm is the combination of
Hash Map and Doubly-Linked List. We initialize a Hash Map in
a pre-defined size to store pairs, and use Doubly-Linked List
to index the pairs in the order of data age.

Maintain the Cache
Once the data with key K is queried, the function get(K)
is first called. If the data of key K is in the cache, t
he cache just returns the data and refresh the data
in the linked list. To refresh data T in the list,
we move the item of data T to the head of the list.
Otherwise, if the data T of key K is not in the cache,
we need to insert the pair into the list. If the cache
is not full, we insert into the hash map, and add the
item at the head of the list. If the cache is already
full, we get the tail of the list and update it with ,
then move this item to the head of the list.

C++ Code
In C++, <hash_map> header file is not in Standard C++ Library,
so stdext namespace should be used for the members of <hash_map>.
*/

#include <list>
//#include <hash_map>
#include <map>
#include <utility>
#include <iterator>

// typedef int K;
// typedef int T;

template <class K, class T> class LRUCache {
using Node = std::pair<K, T>;
using ListIter = typename std::list<Node>::iterator;

private:
  std::list<Node> _freeEntries;
  std::map<K, ListIter> _mapping;
  size_t _size;

public:
  LRUCache(size_t size) : _size(size) {}

  void reset() {
    _mapping.clear();
    _freeEntries.clear();
  }

  void put(K key, T data) {
    auto found = _mapping.find(key);
    if (found != _mapping.end()) {
      // refresh the link list
      _freeEntries.splice(_freeEntries.begin(), _freeEntries, found->second);
      found->second->second = data;
      return;
    }
    if (_mapping.size() == _size) {
      K del = _freeEntries.back().first;
      _freeEntries.pop_back();
      _mapping.erase(del);
    }
    _freeEntries.emplace_front(key, data);
    _mapping[key] = _freeEntries.begin();
  }

  T get(K key) {
    auto found = _mapping.find(key);
    if (found == _mapping.end()) {
      return 0;
    }
    _freeEntries.splice(_freeEntries.begin(), _freeEntries, found->second);
    return found->second->second;
  }

};
