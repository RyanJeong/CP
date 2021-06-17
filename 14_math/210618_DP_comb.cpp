// http://icpc.me/2407
#include <bits/stdc++.h>

using namespace std;

string comb(int n, int m);
string bigNumAdd(string, string);

int n, m;
string dp[101][101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    cout << comb(n,m);

    return 0;
}

// nCr == n-1Cr-1 +  n-1Cr
string comb(int n, int r)
{
    if (n==r || !r) {

        return "1";
    }
    if (dp[n][r]=="") {
        dp[n][r]=bigNumAdd(comb(n-1,r-1),comb(n-1,r));
    }

    return dp[n][r];
}

string bigNumAdd(string str1, string str2)
{
    long long temp = 0;

    string result;
    while (!str1.empty() || !str2.empty() || temp) {
        if (!str1.empty()) {
            temp+=str1.back()-'0';
            str1.pop_back();
        }
        if (!str2.empty()) {
            temp+=str2.back()-'0';
            str2.pop_back();
        }
        result.push_back((temp%10)+'0');
        temp/=10;
    }
    reverse(result.begin(),result.end());

    return result;
}