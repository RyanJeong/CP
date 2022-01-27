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
#include <stack>

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// stack;
using std::stack;

int main() {
  CP;

  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;

  vector<int> res(v.size(), -1);
  stack<int> s;
  for (int i = 0; i < v.size(); ++i) {
    while (!s.empty() && v[s.top()] < v[i]) {
      res[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }
  for (const int& i : res)
    cout << i << ' ';

  return 0;
}
