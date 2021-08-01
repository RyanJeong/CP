// https://www.acmicpc.net/problem/13711
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>a[i];
    }
    vector<int> b(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>b[i];
    }

    // indirect sort
    // a = {5,1,2,3,4}
    // b = {5,4,3,2,1}

    // s[a[1]] = s[5] = 1
    // s[a[2]] = s[1] = 2 
    // s[a[3]] = s[2] = 3 
    // s[a[4]] = s[3] = 4
    // s[a[5]] = s[4] = 5

    // b[1] = s[a[1]] = 1
    // b[2] = s[a[2]] = 2
    // b[3] = s[a[3]] = 3
    // b[4] = s[a[4]] = 4
    // b[5] = s[a[5]] = 5

    //   a  = {5,1,2,3,4}
    //   b  = {5,4,3,2,1}
    //   s  = {2,3,4,5,1}
    // s[a] = {1,2,3,4,5}
    // s[b] = {1,5,4,3,2}
    vector<int> s(n+1);
    for (int i = 1; i<=n; ++i) {
        s[a[i]]=i;
    }
    for (int i = 1; i<=n; ++i) {
        b[i]=s[b[i]];
    }

    vector<int> lis;
    lis.push_back(b[1]); // 0-based
    for (int i = 2; i<=n; ++i) {
        if (b[i]>lis.back()) {
            lis.push_back(b[i]);
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),b[i]);
            lis[cur-lis.begin()]=b[i];
        }
    }
    cout << lis.size();

    return 0;
}
