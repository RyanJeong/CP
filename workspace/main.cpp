#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    set<string> s;
    while (n--) {
        string str;
        cin>>str;
        s.insert(str);
    }

    int res = 0;
    while (m--) {
        string str;
        cin>>str;
        if (s.find(str)==s.end()) {
            continue;
        }
        ++res;
    }
    cout << res;

    return 0;
}