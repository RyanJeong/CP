/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <string>
#include <vector>

// string
using std::string;

// vector
using std::vector;

template <typename T>
vector<int> GetFail(const T& pattern);
template <typename T>
vector<int> Kmp(const T& str, const T& pattern);

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      // idx    : 0 1 2 3 4 5 6
      // pattern: B A B A B A A
      // fail   : 0 0 1 2 3 4 ?
      // ----------------------
      // i = 6, j = 4
      // loop: j > 0 && p[i] != p[j]
      //  if i = 6, j = 4
      //   then j = fail[j-1];
      //   now j = 2
      //  if i = 6, j = 2
      //   then j = fail[j-1];
      //   now j = 0
      //  j is 0, so escape the loop
      // end
      j = fail[j-1];
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
        // ABC    => j = 0;
        // ABCABC => j = 3;
        ans.push_back(i - p.size() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

int main() {
  return 0;
}