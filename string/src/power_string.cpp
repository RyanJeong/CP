// https://www.acmicpc.net/problem/4354
#include <bits/stdc++.h>

using namespace std;

vector<int> get_fail(string);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string s;
        cin>>s;
        if (s==".") {
            break;
        }

        int len = s.size();
        auto fail = get_fail(s);
        if (len%(len-fail.back())) {
            cout << 1 << '\n';
        }
        else {
            cout << len/(len-fail.back()) << '\n';
        }
    }

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

