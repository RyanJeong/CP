// https://www.acmicpc.net/problem/2295
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    
    // a+b+c=d <-> a+b=d-c
    vector<int> tmp;
    for (int i = 0; i<n; ++i) {
        for (int j = i; j<n; ++j) {
            tmp.push_back(v[i]+v[j]);
        }
    }
    sort(tmp.begin(),tmp.end());

    // d는 최대, c는 최소
    for (int i = n-1; i>=0; --i) {
        for (int j = 0; j<n; ++j) {
            if (binary_search(tmp.begin(),tmp.end(),v[i]-v[j])) {
                cout << v[i];

                return 0;
            }
        }
    }

    return 0;
}
