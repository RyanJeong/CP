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

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

template <typename T>
vector<int> GetFail(const T& pattern);

int main() {
  CP;

  // do something ...

  return 0;
}

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];
    if (p[i] == p[j])
      fail[i] = ++j;
  }

  return fail;
}
