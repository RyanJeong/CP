// https://www.acmicpc.net/problem/2571
// 2-d prefix sum
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int paper[101][101];
    int n;
    cin>>n;
    while (n--) {
        int x1, y1;
        cin>>x1>>y1;
        int x2 = min(x1+10,100);
        int y2 = min(y1+10,100);
        for (int i = x1; i<=x2; ++i) {
            for (int j = y1; j<=y2; ++j) {
                paper[i][j]=1;
            }
        }
    }

    for (int i = 1; i<=100; ++i) {
        for (int j = 1; j<=100; ++j) {
            if (!paper[i][j]) {
                continue;
            }


        }
    }


    return 0;
}