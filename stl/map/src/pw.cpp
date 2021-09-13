// https://www.acmicpc.net/problem/17219
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    map<string, string> pw_of;
    while (n--) {
        string site, pw;
        cin>>site>>pw;
        pw_of[site]=pw;
    }

    while (m--) {
        string site;
        cin>>site;
        cout << pw_of[site] << '\n';
    }

    return 0;
}