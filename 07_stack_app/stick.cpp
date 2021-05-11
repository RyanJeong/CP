// http://icpc.me/10799
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int num, cnt;

	num = cnt = 0;
  bool   is_cut;
  string str;

  cin >> str;
  for (char c : str) {
    if (c == '(') {
      is_cut = false;
      ++cnt;
    } else if (c == ')') {
      --cnt;
      num += (is_cut) ? 1 : (is_cut = true, cnt);
    }
  }  
  cout << num;

  return 0;
}