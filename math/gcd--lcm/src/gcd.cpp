#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    sort(v.begin()+1,v.end());
    for (int i = 1; i<n; ++i) {
        v[i+1]=gcd(v[i],v[i+1]);
    }
    cout << v[n];

    return 0;
}

int gcd(int a, int b)
{
    
    return ((b==0) ? a : gcd(b,a%b));
}

