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

  int n, m;
  std::cin >> n >> m;
  std::map<std::string, int> m_stoi;
  std::map<int, std::string> m_itos;
  for (int i = 1; i <= n; ++i) {
    std::string str;
    std::cin >> str;
    m_stoi[str] = i;
    m_itos[i] = str;
  }

  for (int i = 1; i <= m; ++i) {
    std::string str;
    std::cin >> str;
    if (isdigit(str.front()))
      std::cout << m_itos[atoi(str.c_str())] << '\n';
    else
      std::cout << m_stoi[str] << '\n';
  }

  return 0;
}
