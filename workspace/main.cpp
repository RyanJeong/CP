// https://codeforces.com/contest/1446/problem/B
// S(C,D) = 4*LCS(C,D)-|C|-|D|
//        = 2*LCS(C,D)-(LCS(C,D)-|C|)-(LCS(C,D)-|D|)
//        = 2*LCS(C,D)+(|C|-LCS(C,D))+(|D|-LCS(C,D))
// a[i]==b[j] => +2
// else => -1 (LCS에서 길이가 1 늘어남)
/*
A        : abba
B        : babab
LCS(C,D) : abb
|C|      : 3(abb)
|D|      : 4(abab)
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a_len, b_len;
    cin>>a_len>>b_len;
    string a;
    cin>>a;
    a.insert(a.begin(),'\0'); //1-based;
    string b;
    cin>>b;
    b.insert(b.begin(),'\0'); //1-based;

    vector<vector<int>> dp(a_len+1,vector<int>(b_len+1));
    int ans = 0;
    for (int i = 1; i<=a_len; ++i) {
        for (int j = 1; j<=b_len; ++j) {
            if (a[i]==b[j]) {
                dp[i][j]=max(dp[i-1][j-1]+2,dp[i][j]);
            }
            else {
                dp[i][j]=max(0,max(dp[i-1][j],dp[i][j-1])-1);
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans;

    return 0;
}