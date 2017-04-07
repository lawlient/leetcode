/*  Determine whether an integer is a palindrome. Do this without extra space.
 *
 *  Some hints:
 *  Could negative integers be palindromes? (ie, -1)
 *  If you are thinking of converting the integer to string, note the restriction of using extra space.
 *  You could also try reversing an integer.
 *  However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 *  How would you handle such case?
*/

#include <iostream>
#include <algorithm>

bool isPalindromeNumber(int x) {
  std::string s = std::to_string(x);
  std::string rev_s;
  std::reverse_copy(s.begin(), s.end(), std::back_inserter(rev_s));
  return s == rev_s;
}

int main() {
  int x = 0;
  if (isPalindromeNumber(x)) {
    std::cout << x << " is palindrome number\n";
  } else {
    std::cout << x << " is not palindrome number\n";
  }
  return 0;
}
