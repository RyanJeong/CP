// nCk=n!/(n−k)!k!
// nCk = n-1Ck + n-1Ck-1
// https://www.acmicpc.net/problem/11051
#include <bits/stdc++.h>

using namespace std;

int arr[1'005][1'005]; // n combination r = n-1 comb r + n-1 comb r-1
int mod = 10'007;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;

  cin >> n >> k;
  /*
        1      
      1   1
    1   2   1
  1   3   3   1
  */
  for (int i = 1; i <= 1000; ++i) {
    arr[i][0] = arr[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % mod;
    }
  }
  cout << arr[n][k];

  return 0;
}