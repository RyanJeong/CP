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

// string
using std::string;

// vector
using std::vector;

template <typename T>
vector<int> GetFail(const T& pattern);
template <typename T>
vector<int> Kmp(const T& str, const T& pattern);

int main() {
  CP;

  int t;
  cin >> t;
  while (t--) {
    string alphabets, pattern, str;
    cin >> alphabets >> pattern >> str;
    vector<int> res;
    for (int i = 0; i < alphabets.length(); ++i) {
      if (Kmp(str, pattern).size() == 1)
        res.push_back(i);
      for (char& p : pattern) {
        for (int idx = 0; idx < alphabets.length(); ++idx) {
          if (p != alphabets[idx])
            continue;
          int new_idx = ++idx % alphabets.length();
          p = alphabets[new_idx];
          break;
        }
      }
    }
    if (res.empty()) {
      cout << "no solution";
    } else {
      cout << ((res.size() == 1) ? "unique: " : "ambiguous: ");
      for (const int& i : res)
        cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];  // restore the idx
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}

template <typename T>
vector<int> Kmp(const T& s, const T& p) {
  vector<int> fail = GetFail(p);
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j])
      j = fail[j-1];
    if (s[i] == p[j]) {
      if (j == p.size() - 1) {
        ans.push_back(i - p.size() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}
