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
#include <unordered_map>

int main() {
  CP;

  std::unordered_map<std::string, double> umap = {
      {"Jeong", 6.1},
      {"Park", 10.4},
      {"Kim", 11.2}};
  std::string str = "Jeong";
  auto it = umap.find(str);
  if (it == umap.end())
    std::cout << "Not found." << '\n';
  else
    std::cout << it->first << " is " << it->second << '\n';

  std::unordered_multimap<std::string, std::string> ummap = {
      {"Jeong", "C"},
      {"Jeong", "C++"},
      {"Kim", "Java"},
      {"Oh", "Kotlin"}};
  std::cout << ummap.find("Jeong")->second << '\n';

  return 0;
}
