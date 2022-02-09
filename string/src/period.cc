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

template <typename T>
vector<int> GetFail(const T& pattern);

int main() {
  CP;

  while (true) {
    static int idx = 1;
    int t;
    cin >> t;
    if (!t)
      break;
    
    string str;
    cin >> str;
    auto res = GetFail(str);
    for (const auto& i : res)
      cout << i << ' ';
    cout << '\n';
    ++idx;
  }

  return 0;
}

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];  // restore the idx
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}
