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
    vector<int> seq;
    for (int i = 1; i<=n; ++i) {
        vector<bool> is_used(n,false);
        for (int j = 0; j<i; ++j) {
            is_used[j]=true;
        }
        do {
            int sum = 0;
            for (int j = 0; j<n; ++j) {
                if (is_used[j]) {
                    sum+=v[j];
                }
            }
            seq.push_back(sum);
        } while (prev_permutation(is_used.begin(),is_used.end()));
    }
    sort(seq.begin(),seq.end());
    seq.erase(unique(seq.begin(),seq.end()),seq.end());
    int s = 1;
    for (auto cur : seq) {
        if (s!=cur) {
            break;
        }
        ++s;
    }
    cout << s;

    return 0;
}