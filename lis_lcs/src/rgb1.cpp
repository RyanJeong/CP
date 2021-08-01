// https://www.acmicpc.net/problem/1149
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 정의
// d[i][j]
// i번째 집을 j 색으로 칠할 때의 최소 비용
int d[1'001][3];
int r[1'001], g[1'001], b[1'001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 1; i<=n; ++i) {
        cin>>r[i]>>g[i]>>b[i];
    }
    // 2. 초기치 설정
    d[1][0]=r[1];
    d[1][1]=g[1];
    d[1][2]=b[1];
    for (int i = 2; i<=n; ++i) {
        // 3. 점화식 설계
        d[i][0]=min(d[i-1][1],d[i-1][2])+r[i];
        d[i][1]=min(d[i-1][0],d[i-1][2])+g[i];
        d[i][2]=min(d[i-1][0],d[i-1][1])+b[i];
    }
    cout << min({d[n][0],d[n][1],d[n][2]});

    return 0;
}
