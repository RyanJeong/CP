// http://icpc.me/16953
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start, goal;
    cin>>start>>goal;

    vector<int> v;
    queue<pair<long long, int>> q;
    q.push({start,1});

    bool is_hitted = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // 0. check conditions
        long long temp = cur.first;
        int cnt = cur.second;
        if (temp > goal) {
            continue;
        }
        if (temp==goal) {
            is_hitted=true;
            v.push_back(cnt);
            continue;
        }
        // 1. x2
        q.push({temp*2,cnt+1});
        // 2. postfix '1'
        q.push({temp*10+1,cnt+1});
    }
    if (is_hitted) {
        sort(v.begin(),v.end());
        cout << v.front();
    }
    else {
        cout << "-1";
    }

    return 0;
}