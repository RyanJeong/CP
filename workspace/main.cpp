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
    
    int res = 0;
    do {
        int tmp = 0;
        for (int i = 0; i<n-1; ++i) {
            tmp+=abs(v[i]-v[i+1]);
        }
        res=max(res,tmp);
    } while (next_permutation(v.begin(),v.end()));
    cout << res;
    
    return 0;
}