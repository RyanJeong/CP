// http://icpc.me/15664
#include <bits/stdc++.h>

using namespace std;

void rec(int, int);

int  n, m;
int  arr[8];
bool is_used[8];
int  ans[8];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    rec(0,0);

    return 0;
}

void rec(int count, int entry)
{
    if (count==m) {
        for (int i = 0; i<m; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';

        return;
    }

    int prev = -1;

    for (int i = entry; i<n; ++i) {
        if (is_used[i]) {
            continue;
        }
        if (prev!=arr[i]) {
            prev=arr[i];
            ans[count]=arr[i];
            is_used[i]=true;
            rec(count+1,i+1);
            is_used[i]=false;
        }
    }

    return;
}
