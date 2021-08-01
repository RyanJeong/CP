// https://www.acmicpc.net/problem/16474
// 1. 교점 X
// 2. 한 전봇대 당 한 전깃줄
//    -> 최대한 큰 수부터 처리하면 LIS를 최소화할 수 있음 
//       (여러 개 연결된 전깃줄 중 하나만 선택 가능함)
//    -> 1 2 3 -> LIS = {1 2 3}
//    -> 3 2 1 -> LIS = {1}
/* ex
    n: 2, m: 4
    A   B
    1   1
    2   2
        3
        4

    k: 7
    (1 1)
    (1 2)
    (1 3)
    (2 1)
    (2 2)
    (2 3)
    (2 4)

    1) sort
    (1 3), (1 2), (1 1), (2 4), (2 3), (2 2), (2 1)
    -> 3 2 1 4 3 2 1

    2) LIS
    3
    2
    1
    1 4
    1 3
    1 2
    1 2
*/
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>, pair<int, int>);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    map<int, int> a;
    for (int i = 1; i<=n; ++i) {
        int tmp;
        cin>>tmp;
        a[tmp]=i;
    }
    map<int, int> b;
    for (int i = 1; i<=m; ++i) {
        int tmp;
        cin>>tmp;
        b[tmp]=i;
    }
    int k;
    cin>>k;
    vector<pair<int, int>> v(1); // 1-based
    for (int i = 1; i<=k; ++i) {
        int x, y;
        cin>>x>>y;
        v.push_back({a[x],b[y]});
    }

    sort(v.begin(),v.end(),cmp);
    vector<int> lis; // 0-based
    lis.push_back(v[1].second);
    for (int i = 2; i<=k; ++i) {
        if (v[i].second>lis.back()) {
            lis.push_back(v[i].second);
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i].second);
            lis[cur-lis.begin()]=v[i].second;
        }
    }
    cout << k-lis.size();

    return 0;
}

bool cmp(pair<int, int> s, pair<int, int>t)
{
    if (s.first<t.first) {

        return true;
    }
    else if (s.first==t.first && s.second>t.second) {

        return true;
    }
    else {

        return false;
    }
}
