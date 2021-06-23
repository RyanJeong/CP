// http://icpc.me/11055
#include <bits/stdc++.h>

using namespace std;

int a[1'002];
int d[1'002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        d[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int temp = 0;

        for (int j = 1; j < i; ++j) {
            if (d[i] > d[j] && a[i] > a[j]) {
                temp = max(temp, d[j]);
            }
        }
    }

    return 0;
}
