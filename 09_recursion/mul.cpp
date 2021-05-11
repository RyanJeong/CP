// http://icpc.me/1629
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(ll, ll, ll);

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, c;

  cin >> a >> b >> c;
  cout << pow(a, b, c);

  return 0;
}

// 7 -> 3 -> 1, 9 -> 4 -> 2 ->1
ll pow(ll a, ll b, ll c)
{
  if (b == 1) {

    return a % c;
  }
  ll val;

  val = pow(a, b/2, c);
  val = val * val % c;

  // odd? b^2*a, else b^2
  return (b & 01) ? val * a % c : val;
}