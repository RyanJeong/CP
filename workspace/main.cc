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

// iostream
using std::cin;
using std::cout;

// string
using std::string;

int gcd(int, int);
int lcm(int, int);

int main() {
  CP;

  string s, t;
  cin >> s >> t;
  int it_s = lcm(s.size(), t.size()) / s.size();
  string temp_s;
  while (it_s--)
    temp_s += s;
  int it_t = lcm(s.size(), t.size()) / t.size();
  string temp_t;
  while (it_t--)
    temp_t += t;
  cout << (temp_s == temp_t) ? 1 : 0;

  return 0;
}

int gcd(int a, int b) {
  return (!b) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;  // escape overflow
}
