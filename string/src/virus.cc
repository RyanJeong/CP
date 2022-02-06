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
  vector<vector<int>> v;
  while (n--) {
    int len;
    cin >> len;
    vector<int> temp(len);
    for (int &i : temp)
      cin >> i;
    v.push_back(temp);
  }
  bool is_found = false;
  for (int i = 0; i < v.front().size() - k + 1; ++i) {
    vector<int> virus(k);
    for (int j = 0; j < k; ++j)
      virus[j] = v.front().at(i + j);
    vector<int> virus_reverse = virus;
    reverse(virus_reverse.begin(), virus_reverse.end());
    for (int j = 1; j < v.size(); ++j) {
      if (Kmp(v.at(j), virus).empty() && Kmp(v.at(j), virus_reverse).empty())
        continue;
      is_found = true;
      break;
    }
    if (is_found)
      break;
  }
  cout << ((is_found) ? "YES" : "NO");

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
