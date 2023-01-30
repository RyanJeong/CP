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

  std::set<int> s;
  s.insert(3);          // { 3 }
  s.insert({5, 1, 7});  // { 1, 3, 5, 7 }
  if (s.find(6) == s.end())
    std::cout << "6 is not in 's'\n";  // 6 is not in 's'
  else
    std::cout << "6 is in 's'\n";
  std::cout << s.size() << '\n';  // 4

  s.erase(2);   // nop, { 1, 3, 5, 7 }
  s.erase(1);   // { 3, 5, 7 }
  s.insert(3);  // not allowed dup., { 3, 5, 7 }
  for (const auto& i : s)
    std::cout << i << ' ';  // 3 5 7
  std::cout << '\n';
  s.clear();

  std::multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  std::cout << ms.count(1) << '\n';  // { 1, 1, 1 }, => 3

  return 0;
}
