// https://www.acmicpc.net/problem/2579
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 정의
// d[i][j]: i 번째 계단을 밟았으며, 
//          이때 이전에 j 개의 계단을 밟았을 때의 총 점수
int d[302][2]; 
int s[302];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        cin>>s[i];
    }

    if (n==1) {
        cout << s[1];
    } 
    else {
        // 2. 초기치 설정
        // d[1][0]: 이전에 밝은 계단이 없으므로, S[1]
        // d[1][1]: 이전에 밟은 계단이 1개이지만,
        //          i 번째 계단이 시작점이기에 0으로 기록
        // d[2][0]: 이전에 밟은 계단이 없으므로, S[2]
        // d[2][1]: 이전에 밟은 계단이 1개이므로 S[1]+S[2]
        d[1][0]=s[1];
        d[1][1]=0;
        d[2][0]=s[2];
        d[2][1]=s[1]+s[2];
        for (int i = 3; i<=n; ++i) {
            // 3. 점화식 설계
            // 3-1. 이전 계단을 밟지 않을 경우
            // 3-2. 이전 계단을 밟을 경우
            d[i][0]=max(d[i-2][0],d[i-2][1])+s[i];
            d[i][1]=d[i-1][0]+s[i];
        }
        cout << max(d[n][0],d[n][1]);
    }

    return 0;
}
