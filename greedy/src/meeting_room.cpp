// https://www.acmicpc.net/problem/1931
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 
    // 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 
    // 회의의 최대 개수를 찾아보자.

    // 현재 시점보다 뒤에 시작하는 회의 중 가장 빨리 끝나는
    // 회의를 선택하면 최대 회의를 선택할 수 있지 않을까?
    // -> 회의 종료 시간을 기준으로 정렬

    int n;
    cin>>n;
    // {end-time, start-time}
    vector<pair<int, int>> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());

    int cnt = 0;
    int cur = 0;
    for (int i = 1; i<=n; ++i) {
        if (cur>v[i].second) {
            continue;
        }
        ++cnt;
        cur=v[i].first;
    }
    cout << cnt;

    return 0;
}
