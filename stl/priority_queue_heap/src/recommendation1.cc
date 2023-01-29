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
#include <utility>
#include <queue>
#include <functional>
#include <string>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<int> v(1e5 + 1);  // p: 1 ~ 1e5, 1-based
  // pair{level, problem}
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::less<std::pair<int, int>>> max_heap;
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> min_heap;
  while (n--) {
    int p, l;
    std::cin >> p >> l;
    max_heap.push({l, p});
    min_heap.push({l, p});
    v[p] = l;
  }

  int m;
  std::cin >> m;
  while (m--) {
    std::string str;
    std::cin >> str;
    if (str == "recommend") {
      int x;
      std::cin >> x;
      if (x == 1) {
        while (max_heap.top().first != v[max_heap.top().second])
          max_heap.pop();
        std::cout << max_heap.top().second << '\n';
      } else {
        while (min_heap.top().first != v[min_heap.top().second])
          min_heap.pop();
        std::cout << min_heap.top().second << '\n';
      }
    } else if (str == "add") {
      int p, l;
      std::cin >> p >> l;
      max_heap.push({l, p});
      min_heap.push({l, p});
      v[p] = l;
    } else {  // solved
      int p;
      std::cin >> p;
      v[p] = 0;
    }
  }

  return 0;
}
