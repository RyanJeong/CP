// https://www.acmicpc.net/problem/5014
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    vector<int> v(f+1,-1);

    queue<int> q;
    q.push(s);
    v[s]=0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        const int dx[] = {u,-d};
        for (int d : dx) {
            int x = cur+d;

            if (x<1 || x>f) {
                continue;
            }
            if (v[x]!=-1) {
                continue;
            }
            v[x]=v[cur]+1;
            q.push(x);
        }
    }
    if (v[g]==-1) {
        cout << "use the stairs";
    }
    else {
        cout << v[g];
    }

    return 0;
}