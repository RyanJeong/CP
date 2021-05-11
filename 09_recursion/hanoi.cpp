// http://icpc.me/11729
#include <bits/stdc++.h>

using namespace std;

void move(int, int, int);

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;

  cin >> k;
  cout << (1 << k) - 1 << '\n';
  move(1, 3, k);

  return 0;
}

void move(int a, int b, int n)
{
  if (n == 1) {
    cout << a << ' ' << b << '\n';
  } else {
    move(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    move(6 - a - b, b, n - 1);
  }

  return;
}