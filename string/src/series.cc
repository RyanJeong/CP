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
#include <algorithm>

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// algorithm
using std::reverse;

template <typename T>
vector<int> GetFail(const T& pattern);

int main() {
  CP;

  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  reverse(v.begin(), v.end());
  auto res = GetFail(v);
  int common_len = 0;
  for (const int& i : res) {
    if (common_len < i)
      common_len = i;
  }
  if (!common_len) {
    cout << -1;
  } else {
    int cnt = 0;
    for (const int& i : res) {
      if (i == common_len)
        ++cnt;
    }
    cout << common_len << ' ' << cnt;
  }

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
