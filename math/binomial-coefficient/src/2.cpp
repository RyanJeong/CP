// nCk=n!/(n−k)!k!
// nCk = n-1Ck + n-1Ck-1
// https://www.acmicpc.net/problem/11051
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    /*
    pascal triangle
          1      
        1   1
      1   2   1
    1   3   3   1
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<vector<int>> v(n+1,vector<int>(n+1));
    for (int i = 1; i<=n; ++i) {
        v[i][0]=v[i][i]=1;
        for (int j = 1; j<i; ++j) {
            v[i][j]=(v[i-1][j]+v[i-1][j-1])%10'007;
        }
    }
    cout << v[n][k];

    return 0;
}

