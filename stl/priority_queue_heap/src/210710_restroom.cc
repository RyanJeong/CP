/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <queue>

struct Elem {
  int d_;
  int h_;
  int l_;
  bool is_deca_;
};

struct Cmp {
  bool operator()(const Elem& s, const Elem& t) {
    if (s.d_ < t.d_)
      return true;

    if (s.d_ == t.d_ && s.h_ < t.h_)
      return true;

    if (s.d_ == t.d_ && s.h_ == t.h_ && s.l_ > t.l_)
      return true;

    return false;
  }
};

int main() {
  CP;

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::queue<Elem>> q(m + 1);  // 1 ~ m -> 1-based
  for (int i = 1; i <= n; ++i) {
    int d, h;
    std::cin >> d >> h;
    int line = (i % m) ? i % m : m;
    q[line].push({d, h, line, (k--) ? false : true});
  }

  std::priority_queue<Elem, std::vector<Elem>, Cmp> pq;
  for (int i = 1; i <= m; ++i) {
    if (q[i].empty())
      continue;

    auto curr = q[i].front();
    q[i].pop();
    pq.push(curr);
  }
  int cnt = 0;
  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    if (curr.is_deca_)
      break;
    ++cnt;
    if (!q[curr.l_].empty()) {
      pq.push(q[curr.l_].front());
      q[curr.l_].pop();
    }
  }
  std::cout << cnt;

  return 0;
}
