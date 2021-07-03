// https://www.acmicpc.net/problem/7662
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int k;
        cin>>k;
        multiset<int> ms;
        for (int i = 1; i<=k; ++i) {
            char c;
            cin>>c;
            int n;
            cin>>n;
            if (c=='I') {
                ms.insert(n);
            }
            else if (n==1) { // c=='D'
                if (!ms.empty()) {
                    ms.erase(prev(ms.end()));
                }
            }
            else { // c=='D' && i==-1
                if (!ms.empty()) {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *(prev(ms.end())) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}