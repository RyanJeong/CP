// https://www.acmicpc.net/problem/12015
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> lis;
    for (int i = 1; i<=n; ++i) {
        int e;
        cin>>e;

        if (lis.empty() || e>lis.back()) {
            lis.push_back(e);
        }
        else {
            *lower_bound(lis.begin(),lis.end(),e)=e;
        }
    }
    cout << lis.size();

    return 0;
}