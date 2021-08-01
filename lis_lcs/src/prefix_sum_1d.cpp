// https://www.acmicpc.net/problem/11659
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int s[100'001]; // s[i] = s[i-1] + a[i]
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        int a;
        cin>>a;
        s[i]=s[i-1]+a;
    }
    while (m--) {
        int i, j;
        cin>>i>>j;
        cout << s[j]-s[i-1] << '\n';
    }

    return 0;
}
