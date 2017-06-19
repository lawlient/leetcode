/*  All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
 *  When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.  
 *  Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.  
 *
 *  For example, 
 *    Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", 
 *  
 *  Return:
 *    ["AAAAACCCCC", "CCCCCAAAAA"].
 *  
 *  
 *  
 *
*/

/*  hashTable && bit operation
 *  A G C T are different in the last three bits.
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
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::unordered_map<int, int> count;
    std::vector<std::string> res;
    size_t i = 0;
    int key = 0;
    while (i < 9) {
      key = key << 3 | (s[i++] & 7);
    }
    while (i < s.length()) {
      if (count[key = (key << 3 & 0x3FFFFFFF) | (s[i++] & 7)]++ == 1)
        res.push_back(s.substr(i-10, 10));
    }
    return res;
  }
};

int main() {
}
