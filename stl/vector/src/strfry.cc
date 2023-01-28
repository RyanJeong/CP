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
#include <vector>

int main() {
  CP;

  int n;
  std::cin >> n;
  while (n--) {
    std::string tmp_a, tmp_b;
    std::cin >> tmp_a >> tmp_b;

    std::vector<int> freq(26);
    for (const char& c : tmp_a)
      ++freq[c-'a'];
    for (const char& c : tmp_b)
      --freq[c-'a'];

    bool is_true = true;
    for (const int& i : freq) {
      if (!i)
        continue;
      is_true = false;
      break;
    }
    std::cout << (is_true ? "Possible" : "Impossible") << '\n';
  }

  return 0;
}
