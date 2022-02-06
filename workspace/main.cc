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

vector<int> GetFail(const string& pattern);
vector<int> Kmp(const string& str, const string& pattern);

vector<int> GetFail(const string& p) {
  vector<int> fail(p.length());
  int j = 0;
  for (int i = 1; i < p.length(); i++) {
    while (j > 0 && p[i] != p[j])
      // idx    : 0 1 2 3 4 5 6
      // pattern: B A B A B A A
      // fail   : 0 0 1 2 3 4 ?
      //
      // fail(4) = 3:
      //  p[2-4] and p[0-2] is equal, so start at index 3
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

vector<int> Kmp(const string& s, const string& p) {
  vector<int> fail = GetFail(p);
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < s.length(); i++) {
    while (j > 0 && s[i] != p[j])
      j = fail[j-1];
    if (s[i] == p[j]) {
      if (j == p.length() - 1) {
        // ABC    => j = 0;
        // ABCABC => j  3;
        ans.push_back(i - p.length() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

int main() { return 0; }