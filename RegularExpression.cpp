#include <iostream>
#include <algorithm>
#include <vector>

bool helper(std::string s, std::string p, int i, int j) {
  int sl = s.length(), pl = p.length();
  if (j == pl) {
      return i == sl;
  }
  if (j == pl - 1 || p.at(j + 1) != '*') {
    if (i == sl || (s.at(i) != p.at(j) && p.at(j) != '.')) { return false; }
    return helper(s, p, i + 1, j + 1);
  }
  while (i < sl && (s.at(i) == p.at(j) || p.at(j) == '.')) {
    if (helper(s, p, i, j + 2)) {
      return true;
    }
    i++;
  }
  return helper(s, p, i, j + 2);
}

bool isMatch(std::string s, std::string p) {
  return helper(s, p, 0, 0);
}

int main() {
  std::string s = "aab", p = "c*a*b";
  std::cout << isMatch(s, p) << std::endl;
  return 0;
}
