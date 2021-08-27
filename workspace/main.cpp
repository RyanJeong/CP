#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    vector<int> v(3);
    for (int i = 1; i<=t; ++i) {
        for (int j = 0; j<v.size(); ++j) {
            cin>>v[j];
        }
        sort(v.begin(),v.end());
        cout << "Scenario #" << i << ":\n";
        cout << ((v[0]*v[0]+v[1]*v[1] == v[2]*v[2]) ? "yes\n" : "no\n");
        if (i<t) {
            cout << '\n';
        }
    }

    return 0;
}