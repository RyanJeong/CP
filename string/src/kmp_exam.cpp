// https://www.acmicpc.net/problem/16916
#include <bits/stdc++.h>

using namespace std;

vector<int> get_fail(string);
vector<int> kmp(string, string);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    string p;
    getline(cin,p);

    auto res = kmp(s,p);
    cout << (!res.empty());

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

vector<int> kmp(string s, string p)
{
    auto fail = get_fail(p);
    int n_s = (int)s.size();
    int n_p = (int)p.size();

    vector<int> ans;
    for (int i = 0, j = 0; i<n_s; i++) {
        while (j>0 && s[i]!=p[j]) {
            j=fail[j-1];
        }
        if (s[i]==p[j]) {
            if (j==n_p-1){
                ans.push_back(i-n_p+1);
                j=fail[j];
            }
            else {
                j++;
            }
        }
    }

    return ans;
}