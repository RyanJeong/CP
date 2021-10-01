// https://www.acmicpc.net/problem/1701
#include <bits/stdc++.h>

using namespace std;

vector<int> get_fail(string);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    int ans = 0;
    for (int i = 0; i<s.size(); ++i) {
        string p = s.substr(i,s.size());
        auto fail = get_fail(p);
        sort(fail.begin(),fail.end());
        ans=max(ans,fail.back());
    }
    cout << ans;

    return 0;
}

vector<int> get_fail(string p)
{
    int n_p = p.size();
    vector<int> fail(n_p);
    for (int i = 1, j = 0; i<n_p; i++) {
        while (j>0 && p[i]!=p[j]) {
            j=fail[j-1];
        }
        if (p[i]==p[j]) {
            fail[i]=j+1;
            ++j;
        }
    }

    return fail;
}