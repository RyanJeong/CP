// https://www.acmicpc.net/problem/10808
#include <bits/stdc++.h>

using namespace std;

int main(void)
{    
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int freq[26] = {0};
  string s;
  cin>>s;

  for (auto c : s) {
    freq[c-'a']++;
  }
  for (int i = 0; i<26; ++i) {
    cout << freq[i] << ' ';
  }

  return 0;
}