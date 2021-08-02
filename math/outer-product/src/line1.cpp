// https://www.acmicpc.net/problem/17386
#include <bits/stdc++.h>

using namespace std;

/*
        A
    C-+-D
        B

    A
    |	C
    B	|
        D

    1. A-B-C, A-B-D
    2. C-D-A, C-D-B
*/
int is_ccw(pair<int, int>, pair<int, int>, pair<int, int>);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> a, b, c, d;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    cin>>d.first>>d.second;
    do {
        // A-B-C, A-B-D
        if (!(is_ccw(a,b,c)*is_ccw(a,b,d)<0)) {
            break;
        }
        // C-D-A, C-D-B
        if (!(is_ccw(c,d,a)*is_ccw(c,d,b)<0)) {
            break;
        }
        cout << 1;

        return 0;
    } while (0);
    cout << 0;

    return 0;
}

int is_ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long u1 = b.first-a.first;
    long long v1 = b.second-a.second;
    long long u2 = c.first-b.first;
    long long v2 = c.second-b.second;
    long long tmp = u1*v2-u2*v1;

    return ((tmp>0) ? 1 : (tmp<0) ? -1 : 0);
}
