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

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// string
using std::string;

template <typename T>
vector<int> GetFail(const T& pattern);

int main() {
  CP;

  string str;
  int k;
  cin >> str >> k;
  auto fail = GetFail(str);
  // aba, fail[2] = 1 a(0): prefix, a(2): suffix
  // ababa,           a(2): new prefix, a(4): new suffix
  // abababa,         a(4): new prefix, a(6): new suffix
  // -> len + (k - 1) * (len - prefix(=suffix)'s length)
  // k's max = 1e6, max(len - prefix's length) = 5e5
  // 5e11 > max(int)
  int64_t offset = str.length() - fail.back();
  cout << str.length() + (k - 1) * offset;

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
