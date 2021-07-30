// https://www.acmicpc.net/problem/1700
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> v(k+1);
    vector<int> freq(k+1);
    for (int i = 1; i<=k; ++i) {
        cin>>v[i];
        ++freq[v[i]];
    }
    set<int> s;
    int res = 0;
    for (int i = 1; i<=k; --freq[v[i++]]) {
        if (s.count(v[i])) {
            continue;
        }
        if (s.size()<n) {
            s.insert(v[i]);
            continue;
        }
        // 공간이 부족해 사용중인 플러그 중 하나를 제거해야 함
        ++res;
        // 뒤에서 더 이상 사용하지 않는 플러그 우선 제거
        bool is_solved = false;
        for (int e : s) {
            if (!freq[e]) {
                s.erase(e);
                s.insert(v[i]);
                is_solved=true;
                break;
            }
        }
        // 사용중인 플러그가 뒤에서 재사용된다면, 
        // 가장 오래동안 사용하지 않는 플러그 제거
        /*  ex. 
            2 6
            1 2 3 1 2 3

            1
            1 2
            1 3 by 2
            1 3
            2 3 by 1
            => 2

            1
            1 2
            2 3 by R2
            1 3 by R2
            2 3 by 1
            => 3
        */
        if (is_solved) {
            continue;
        }
        int e = 0;
        vector<bool> is_checked(k+1);
        for (int j = i+1; j<=k; ++j) {
            if (s.count(v[j]) && !is_checked[v[j]]) {
                e=v[j];
                is_checked[e]=true;
            }
        }
        s.erase(e);
        s.insert(v[i]);
    }
    cout << res;

    return 0;
}