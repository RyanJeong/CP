#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
        sum+=v[i];
    }

    sum/=2;
    bool is_used = false;
    for (auto i : v) {
        if (!is_used && i==sum) {
            is_used=true;
            continue;
        }
        cout << i << ' ';
    }
    cout << sum;

    return 0;
}