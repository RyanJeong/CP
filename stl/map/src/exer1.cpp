// https://www.acmicpc.net/problem/1620
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;
    map<string, int> m_stoi;
    map<int, string> m_itos;
    for (int i = 1; i<=n; ++i) {
        string str;
        cin>>str;
        m_stoi[str]=i;
        m_itos[i]=str;
    }
    for (int i = 1; i<=m; ++i) {
        string str;
        cin>>str;
        if (isdigit(str.front())) {
            cout << m_itos[atoi(str.c_str())] << '\n';
        }
        else {
            cout << m_stoi[str] << '\n';
        }
    }

    return 0;
}