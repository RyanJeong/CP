// https://www.acmicpc.net/problem/9375
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        map<string, int> m;
        for (int i = 0; i<n; ++i) {
            string val, key;
            cin>>val>>key;
            if (m.find(key)==m.end()) {
                m[key]=1;
            }
            else {
                ++m[key];
            }
        }
        int mul = 1;
        // {3 2 1 0} x {2 1 0} - n(0)
        for (auto cur : m) {
            mul*=cur.second+1;
        }
        cout << mul-1 << '\n';
    }

    return 0;
}
