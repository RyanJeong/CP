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

int main() {
  CP;

  string str;
  cin >> str;
  int arr[26] = { 0 };
  for (const char& c : str)
    ++arr[c-'a'];
  for (int i = 0; i < 26; ++i)
    cout << arr[i] << ' ';

  return 0;
}
