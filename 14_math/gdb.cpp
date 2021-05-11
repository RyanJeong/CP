// http://icpc.me/17087
#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s;

  cin >> n >> s;
  vector<int> v;

  for (int i = 0; i < n; ++i) {
    int temp;

    cin >> temp;
    v.push_back(abs(s - temp));
  }
  int res;

  for (res = v.back(), v.pop_back(); !v.empty(); v.pop_back()) {
    res = gcd(res, v.back());
  }
  cout << res;

  return 0;
}

int gcd(int x, int y)
{
  
  return (y == 0 ? x : gcd(y, x % y));
}
