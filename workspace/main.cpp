// https://www.acmicpc.net/problem/13305
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<long long> dist(n);
    for (int i = 1; i<n; ++i) {
        cin>>dist[i];
    }
    vector<long long> cost(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>cost[i];
    }

    // 이전 주유소에서의 가격과 현재 주유소의 가격을 비교해
    // 더 저렴한 가격을 찾아 다음 도시까지 이동해야 하는
    // 거리를 곱해 합산해가면 불필요한 연산을 줄일 수 있음
    long long cur = 2e9;
    long long res = 0;
    for (int i = 1; i<n; ++i) {
        cur=min(cur,cost[i]);
        res+=cur*dist[i];
    }
    cout << res;

    return 0;
}