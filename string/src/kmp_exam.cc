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
#include <vector>

// iostream
using std::cin;
using std::cout;
using std::getline;

// string
using std::string;

// vector
using std::vector;

vector<int> GetFail(const string& pattern);
vector<int> Kmp(const string& str, const string& pattern);

int main() {
  CP;

  string s;
  getline(cin, s);
  string p;
  getline(cin, p);

  auto res = Kmp(s, p);
  cout << (!res.empty());

  return 0;
}

vector<int> GetFail(const string& p) {
  vector<int> fail(p.length());
  int j = 0;
  for (int i = 1; i < p.length(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];  // restore the idx
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}

vector<int> Kmp(const string& s, const string& p) {
  vector<int> fail = GetFail(p);
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < s.length(); i++) {
    while (j > 0 && s[i] != p[j])
      j = fail[j-1];
    if (s[i] == p[j]) {
      if (j == p.length() - 1) {
        ans.push_back(i - p.length() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}
