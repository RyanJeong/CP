// https://www.acmicpc.net/problem/17387
#include <bits/stdc++.h>

using namespace std;

/*
    A-B     C-D, y=c
    A-BC-D,     y=c
    A-C=B-D
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
        if (is_ccw(a,b,c)*is_ccw(a,b,d)>0) {
            break;
        }
        // C-D-A, C-D-B
        if (is_ccw(c,d,a)*is_ccw(c,d,b)>0) {
            break;
        }
        /*     
                a
               /
            (b c)
             /
            d
        */
        if (is_ccw(a,b,c)==0 && is_ccw(a,b,d)==0
            && is_ccw(c,d,a)==0 && is_ccw(c,d,b)==0) {
            if (!(max(a.first,b.first)>=min(c.first,d.first)
                && max(c.first,d.first)>=min(a.first,b.first)
                && max(a.second,b.second)>=min(c.second,d.second)
                && max(c.second,d.second)>=min(a.second,b.second))) {
                break;
            }
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
