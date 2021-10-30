#include <iostream>
#include <string>
#include <algorithm>

int main() {
  while (true) {
    std::string s;
    std::cin >> s;
    if (s == "#") {
      break;
    }
    std::string res;
    std::reverse(s.begin(), s.end());
    for (auto c : s) {
      if (c == 'b') {
        res.push_back('d');
      } else if (c == 'd') {
        res.push_back('b');
      } else if (c == 'p') {
        res.push_back('q');
      } else if (c == 'q') {
        res.push_back('p');
      } else if (c == 'i' || c == 'o' || c == 'v' || c == 'w' || c == 'x') {
        res.push_back(c);
      } else {
        res = "INVALID";
        break;
      }
    }
    std::cout << res << std::endl;
  }
}
