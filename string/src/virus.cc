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
#include <algorithm>

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// vector
using std::vector;

// algorithm
using std::reverse;

template <typename T>
vector<int> GetFail(const T& pattern);
template <typename T>
vector<int> Kmp(const T& str, const T& pattern);

int main() {
  CP;

  int n, k;
  cin >> n >> k;
  vector<int> virus;
  vector<vector<int>> codes;
  while (n--) {
    int len;
    cin >> len;
    vector<int> temp(len);
    for (int &i : temp)
      cin >> i;
    if (virus.empty())
      virus = temp;
    else
      codes.push_back(temp);
  }

  bool is_virus = false;
  for (int i = 0; i < virus.size() - k + 1; ++i) {
    vector<int> virus_pattern(virus.begin() + i, virus.begin() + i + k);
    vector<int> virus_reverse_pattern(virus_pattern);
    reverse(virus_reverse_pattern.begin(), virus_reverse_pattern.end());
    bool is_found = true;
    for (const auto& code : codes) {
      if (Kmp(code, virus_pattern).empty() &&
          Kmp(code, virus_reverse_pattern).empty()) {
        is_found = false;
        break;
      }
    }
    if (is_found) {
      is_virus = true;
      break;
    }
  }
  cout << ((is_virus) ? "YES" : "NO");

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
