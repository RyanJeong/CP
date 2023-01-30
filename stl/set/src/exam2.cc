/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <unordered_set>
#include <string>

int main() {
  CP;

  std::unordered_set<std::string> us = {"red", "green", "blue"};
  std::string color = "red";
  auto it = us.find(color);

  if (it == us.end())
    std::cout << "not found.";
  else
    std::cout << *it << " is in the container.";  // red is in the container.
  std::cout << '\n';

  std::unordered_multiset<std::string> ums = {
      "red",
      "green",
      "red",
      "blue",
      "green"};
  if (ums.find("red") == ums.end())
    std::cout << "not found.";
  else
    std::cout << *ums.find("red") << " found.";  // red found.
  std::cout << '\n';

  return 0;
}
