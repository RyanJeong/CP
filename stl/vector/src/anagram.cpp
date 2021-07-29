#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str1, str2;
  int    alpha[26] = { 0 };

  cin >> str1 >> str2;
  for (char c : str1) {
    ++alpha[c-'a'];
  }
  for (char c : str2) {
    --alpha[c-'a'];
  }
  int num;

  num = 0;
  for (int i : alpha) {
    num += (i < 0) ? -i : i;
  }
  cout << num;

  return 0;
}