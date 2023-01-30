/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <set>

int main() {
  CP;

  int t;
  std::cin >> t;
  while (t--) {
    int k;
    std::cin >> k;
    std::multiset<int> ms;
    while (k--) {
      char c;
      std::cin >> c;
      int n;
      std::cin >> n;
      if (c == 'I') {
        ms.insert(n);
      } else if (n == 1) {  // c == 'D'
        if (!ms.empty())
          ms.erase(prev(ms.end()));
      } else {  // c == 'D' && n == -1
        if (!ms.empty())
          ms.erase(ms.begin());
      }
    }
    if (ms.empty())
      std::cout << "EMPTY\n";
    else
      std::cout << *(std::prev(ms.end())) << ' ' << *ms.begin() << '\n';
  }

  return 0;
}
