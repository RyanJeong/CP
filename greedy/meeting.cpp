// http://icpc.me/1931
#include <bits/stdc++.h>

using namespace std;

pair<int, int> d[100'002]; // 0, 1 ~ 100,000, OOB

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    int cur = 0;
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>d[i].second>>d[i].first;
    }

    sort(d,d+n);
    for (int i = 0; i<n; ++i) {
        if (cur>d[i].second) {
            continue;
        }
        ++cnt;
        cur=d[i].first;
    }
    cout << cnt;

    return 0;
}