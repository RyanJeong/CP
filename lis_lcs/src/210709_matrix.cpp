// https://www.acmicpc.net/problem/11049
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> matrix;
vector<vector<int>> dp;

int rec(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    matrix=vector<pair<int, int>>(n+1); // row, col
    dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    for (int i = 1; i<=n; ++i) {
        cin>>matrix[i].first>>matrix[i].second;
    }

    cout << rec(1,n);

    return 0;
}

int rec(int low, int high)
{
    if (low==high) {

        return 0;
    }
    int& res = dp[low][high];
    if (~res) {

        return res;
    }
    res=INT_MAX;
    for (int mid = low; mid < high; ++mid) {
        // (row[low],col[mid]) X (row[mid+1],col[high])
        int tmp = matrix[low].first*matrix[mid].second*matrix[high].second;
        res = min(res, rec(low,mid)+rec(mid+1,high)+tmp);
    }

    return res;
}