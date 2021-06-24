// http://icpc.me/1822
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    set<int> s;

    while (a--) {
        int temp;
        cin>>temp;

        s.insert(temp);
    }
    while (b--) {
        int temp;
        cin>>temp;
        auto cur = s.find(temp);

        if (cur!=s.end()) {
            s.erase(cur);
        }
    }

    cout << s.size() << '\n';
    for (int i : s) {
        cout << i << ' ';
    }

    return 0;
}