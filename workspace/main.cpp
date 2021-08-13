// https://www.acmicpc.net/problem/11404
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> floyd(n+1,vector<int>(n+1));
    // 문제에서 올 수 있는 최대값보다 큰 값으로 초기 간선 가중치 초기화
    // 2e9는 오버플로우가 발생하기 때문에 최대값 설정에 주의해야 함
    fill(floyd.begin(),floyd.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        floyd[i][i]=0;
    }
    while (m--) {
        int a, b, c;
        cin>>a>>b>>c;
        floyd[a][b]=min(floyd[a][b],c);
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (floyd[i][j]==1e9) {
                cout << 0;
            }
            else {
                cout << floyd[i][j];
            }
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
