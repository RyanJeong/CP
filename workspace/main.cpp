// https://www.acmicpc.net/problem/1707
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
    vector<int> op;
    for (int i = 0; i<4; ++i) {
        int tmp;
        cin>>tmp;
        while (tmp--) {
            op.push_back(i);
        }
    }
    int min_val = 1e9;
    int max_val = -1e9;
    do {
        vector<int> tmp(v);
        for (int i = 0; i<op.size(); ++i) {
            switch (op[i]) {
            case 0:
                tmp[i+1]=tmp[i]+tmp[i+1];
                break;
            case 1:
                tmp[i+1]=tmp[i]-tmp[i+1];
                break;
            case 2:
                tmp[i+1]=tmp[i]*tmp[i+1];
                break;
            case 3:
                tmp[i+1]=tmp[i]/tmp[i+1];
                break;
            default:
                break;
            }
        }
        min_val=min(min_val,tmp.back());
        max_val=max(max_val,tmp.back());
    } while (next_permutation(op.begin(),op.end()));
    cout << max_val << '\n' << min_val;

    return 0;
}