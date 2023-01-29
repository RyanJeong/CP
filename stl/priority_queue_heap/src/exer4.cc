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

// 비교 대상은 Node의 value
struct Node {
  int from;
  int to;
  int value;
};

struct CmpLess {
  bool operator()(const Node& s, const Node& t) {
    return s.value < t.value;
  }
};

struct CmpGreater {
  bool operator()(const Node& s, const Node& t){
    return s.value > t.value;
  }
};

int main() {
  CP;

  std::priority_queue<Node, std::vector<Node>, CmpLess> max_heap;
  std::priority_queue<Node, std::vector<Node>, CmpGreater> min_heap;

  max_heap.push({1, 1, 4});
  max_heap.push({1, 2, 1});
  max_heap.push({2, 1, 3});
  max_heap.push({1, 3, 5});
  max_heap.push({3, 3, 2});
  std::cout << "{ " << max_heap.top().from << ", "
     << max_heap.top().to << ", "
     << max_heap.top().value << " }\n";  // { 1, 3, 5 }

  min_heap.push({1, 1, 4});
  min_heap.push({1, 2, 1});
  min_heap.push({2, 1, 3});
  min_heap.push({1, 3, 5});
  min_heap.push({3, 3, 2});
  std::cout << "{ " << min_heap.top().from << ", "
     << min_heap.top().to << ", "
     << min_heap.top().value << " }\n";  // { 1, 2, 1 }

  return 0;
}
