// http://icpc.me/15656
#include <bits/stdc++.h>

using namespace std;

void rec(int);

int n, m;
int arr[8]; 
int ans[8];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    rec(0);

    return 0;
}

void rec(int count)
{
    if (count==m) {
        for (int i = 0; i<m; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = 0; i<n; ++i) {
        ans[count]=arr[i];
        rec(count+1);
    }

    return;
}




