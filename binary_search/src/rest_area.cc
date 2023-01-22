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

int main() {
  CP;

  // 최적화문제
  //   * M 개의 휴게소를 더 지어서 휴게소가 없는 구간의 길이의 최대값을 최소로
  // 결정문제
  //   * 휴게소를 x의 거리마다 지었을 때, 지을 수 있는 휴게소의 개수가 n개인가?
  int n, m, l;
  std::cin >> n >> m >> l;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  v.push_back(0);  // lower_bound
  v.push_back(l);  // upper_bound
  n += 2;          // n(lower_bound, upper_bound)
  sort(v.begin(), v.end());

  int low = v.front() + 1;  // 고속도로 양 끝에는 휴게소를 설치 못 함
  int high = v.back();      // [low, high)
  while (low < high) {
    int mid = (low + high) / 2;
    if (!mid)
      break;

    int cnt = 0;
    for (int i = 1; i < n; ++i)
      cnt += (v[i] - v[i-1] - 1) / mid;
    if (cnt > m)
      low = mid + 1;
    else
      high = mid;
  }
  std::cout << low;

  return 0;
}
