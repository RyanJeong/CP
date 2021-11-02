/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, l, h;
  std::cin >> n >> l >> h;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  sort(v.begin(), v.end());

  double sum = 0;
  while (h--) {
    v.pop_back();
  }
  int cnt = 0;
  for (const auto& i : v) {
    if (l > 0) {
      --l;
      continue;
    }
    sum += i;
    ++cnt;
  }
  std::cout.precision(16);
  std::cout << sum / cnt;

  return 0;
}

