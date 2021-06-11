// http://icpc.me/18870
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n); // size

    for (int i = 0; i<n; ++i) cin>>v[i];        
    vector<int> v_buf{v}; // copy
    sort(v_buf.begin(),v_buf.end());

    v_buf.erase(unique(v_buf.begin(),v_buf.end()),v_buf.end()); // Unique: 
                                                                // Forward iterator to the new end of the range.
    for (int i = 0; i<n; ++i) {
        auto p = lower_bound(v_buf.begin(),v_buf.end(),v[i]);

        cout << p - v_buf.begin() << ' ';
    }

    return 0;
}