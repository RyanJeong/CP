// http://icpc.me/2493
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    stack<pair<int, int>> s; // <index, value>

    for (int i = 1; i<=n; ++i) {
        int num;
        cin>>num;

        while (!s.empty()) {
            if (s.top().second>num) {
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }
        if (s.empty()) {
            cout << 0 << ' ';
        }
        s.push(make_pair(i,num));
    }

    return 0;
}