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

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// vector
using std::vector;

int main() {
  CP;

  int n;
  cin >> n;
  while (n--) {
    string tmp_a, tmp_b;
    cin >> tmp_a >> tmp_b;

    vector<int> freq(26);
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
    cout << (is_true ? "Possible" : "Impossible") << '\n';
  }

  return 0;
}
