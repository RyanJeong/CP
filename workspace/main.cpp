#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, m, M, T, R, t, e, h;
    cin>>N>>m>>M>>T>>R;
 
    if (m+T>M) {
        cout << -1;

        return 0;
    }
    t=0;
    e=0;
    h=m;
    while (e<N) {
        if (h+T<=M) {
            h+=T;
            ++e;
        }
        else {
            h=((h-R<m)? m : h-R);
        }
        ++t;
    }
    cout << t;
 
    return 0;
}
