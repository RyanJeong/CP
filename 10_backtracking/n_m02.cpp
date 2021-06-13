// http://icpc.me/15650
#include <bits/stdc++.h>

using namespace std;

void rec(int, int);

int  n, m;
int  arr[9]; // 0, 1 ~ 8
bool is_used[9];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    rec(0,1);

    return 0;
}

void rec(int count, int entry)
{
    if (count==m) {
        for (int i = 0; i<m; ++i) {
            cout << arr[i] << ' ';
        }
        cout <<'\n';

        return;
    }
    for (int i = entry; i<=n; ++i) {
        if (!is_used[i]) {
            arr[count]=i;
            is_used[i]=true;
            rec(count+1,i+1);
            is_used[i]=false;
        }
    }

    return;
}