/*  Given an integer, convert it to a roman numeral.
 *  Input is guaranteed to be within the range from 1 to 3999.  
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::string intToRoman(int x) {
  std::vector<std::string> base = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                                   "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                                   "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                                   "", "M", "MM", "MMM"};
  return base[x/1000 + 30] + base[(x/100)%10 + 20] + base[(x/10)%10 + 10] + base[x%10];
}

int main() {
  std::cout << intToRoman(1) << std::endl;
  return 0;
}
