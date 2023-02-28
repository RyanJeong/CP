/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <string>
#include <map>

int main() {
  CP;

  // key: string, value: int
  std::map<std::string, int> m;
  m["Jeong"] = 123456;
  m["Oh"] = 234567;
  m["Park"] = 345678;

  /*
    Jeong 123456
    Oh 234567
    Park 345678
  */
  for (const auto& i : m)
    std::cout << i.first << ' ' << i.second << '\n';

  m["Park"] = 876543;
  std::cout << m["Park"] << '\n';  // 876543

  m.erase("QWERT");  // nop
  m.erase("Park");   // "Park" will be removed

  /*
    Jeong 123456
    Oh 234567
  */
  for (const auto& i : m)
    std::cout << i.first << ' ' << i.second << '\n';
  m.clear();  // clear the map

  // key: int, value: string
  std::multimap<int, std::string> ms;
  ms.insert({1, "Hi" });
  ms.insert({1, "Hello" });
  ms.insert({2, "Bye" });

  /*
    1 Hi
    1 Hello
    2 Bye
  */
  for (const auto& i : ms)
    std::cout << i.first << ' ' << i.second << '\n';

  return 0;
}
