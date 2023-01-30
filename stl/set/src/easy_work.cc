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
#include <string>
#include <functional>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::set<std::string, std::greater<std::string>> s;
  while (n--) {
    std::string name, state;
    std::cin >> name >> state;
    if (state == "enter") {
      s.insert(name);
    } else {  // leave
      if (s.find(name) != s.end())
        s.erase(name);
    }
  }
  
  for (const std::string& name : s)
    std::cout << name << '\n';

  return 0;
}
