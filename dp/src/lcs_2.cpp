// https://www.acmicpc.net/problem/9252
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin>>a>>b;
    int a_len = a.size();
    int b_len = b.size();
    a.insert(a.begin(), '\0'); // 1-based
    b.insert(b.begin(), '\0'); // 1-based

    static int c[1001][1001]; // init. all to zero
    for (int i = 1; i<=a_len; ++i) {
        for (int j = 1; j<=b_len; ++j) {
            if (a[i]==b[j]) {
                c[i][j]=c[i-1][j-1]+1;
            }
            else {
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    cout << c[a_len][b_len] << '\n';

    // get lcs
    stack<char> s;
    int a_idx = a_len;
    int b_idx = b_len;
    while (c[a_idx][b_idx]) {
        if (a[a_idx]==b[b_idx]) {
            s.push(a[a_idx]);
            --a_idx;
            --b_idx;
        }
        else {
            if (c[a_idx][b_idx-1]>c[a_idx-1][b_idx]) {
                --b_idx;
            }
            else {
                --a_idx;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
