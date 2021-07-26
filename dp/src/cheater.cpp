// https://www.acmicpc.net/problem/9251
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a_len, b_len;
    cin>>a_len>>b_len;
    string a;
    cin>>a;
    string b;
    cin>>b;

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

    int a_idx = a_len;
    int b_idx = b_len;
    stack<char> s;
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

/*
    int a_to = a.rfind(s.top());
    int b_to = b.rfind(s.top());
    s.pop();
    a_idx=a_to;
    b_idx=b_to;
    while (!s.empty()) {
        while (a[a_idx--]!=s.top()) {
            ;
        }
        while (b[b_idx--]!=s.top()) {
            ;
        }
        s.pop();
    }

    cout << 4*c[a_len][b_len]-(a_to-a_idx)-(b_to-b_idx);
    */
   cout << c[a_len][b_len];

    return 0;
}
