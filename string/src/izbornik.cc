/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
  CP;

  std::vector<bool> is_used(26);
  int n;
  std::cin >> n;
  std::cin.ignore();
  std::vector<std::vector<std::string>> v(n);

  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::getline(std::cin, tmp, '\n');

    std::stringstream ss(tmp);
    while (std::getline(ss, tmp, ' '))
      v[i].push_back(tmp);

    // process
    bool is_failed = true;
    for (std::string& str : v[i]) {
      char c = str.front();
      int idx = tolower(c)-'a';
      if (is_used[idx])
        continue;

      is_used[idx] = true;
      str.insert(str.begin(), '[');
      str.insert(str.begin() + 2, ']');
      is_failed = false;
      break;
    }
    if (!is_failed)
      continue;

    for (std::string& str : v[i]) {
      for (auto it = str.begin(); it != str.end(); ++it) {
        int idx = tolower(*it)-'a';
        if (is_used[idx])
          continue;

        is_used[idx] = true;
        str.insert(it, '[');
        str.insert(it + 2, ']');
        is_failed = false;
        break;
      }
      if (!is_failed)
        break;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (std::string& str : v[i])
      std::cout << str << ' ';
    std::cout << '\n';
  }

  return 0;
}
