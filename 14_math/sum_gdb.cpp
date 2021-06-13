// http://icpc.me/9613
#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    while (n--) {
        long long sum = 0;
        int m;
        cin>>m;
        int arr[m];
        for (int i = 0; i<m; ++i) {
            cin>>arr[i];
        }

        for (int i = 0; i<m-1; ++i) {
            for (int j = i + 1; j<m; ++j) {
                sum+=gcd(arr[i],arr[j]);
            }
        }
        cout << sum << '\n';
    }

    return 0;
}

int gcd(int x, int y)
{
    
    return ((y == 0) ? x : gcd(y,x%y));
}