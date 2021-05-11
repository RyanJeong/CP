// http://icpc.me/5648
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  vector<long long> v;

  for (int i = 0; i < n; ++i) {
    string str;

    cin >> str;
    reverse(str.begin(), str.end());
    v.push_back(atoll(str.c_str()));
  }
  sort(v.begin(), v.end());
  for (long long i : v) {
    cout << i << '\n';
  }

  return 0;
}