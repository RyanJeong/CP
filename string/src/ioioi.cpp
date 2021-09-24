// https://www.acmicpc.net/problem/5525
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, len;
    cin>>n>>len;
    string str;
    cin>>str;

    int res = 0;
    int cnt = 0;
    int i = 0;
    while (i<str.length()-2) {
        if (str[i]=='I' && str[i+1]=='O' && str[i+2]=='I') {
            ++cnt;
            if (cnt==n) {
                ++res;
                --cnt;
            }
            i+=2;
        }
        else {
            cnt=0;
            ++i;
        }

    }
    cout << res;

    return 0;
}
