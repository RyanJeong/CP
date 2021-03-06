#include <bits/stdc++.h>

using namespace std;

// 1: ccw, -1: cw, 0: on the line
int is_ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long u1 = b.first-a.first;
    long long v1 = b.second-a.second;
    long long u2 = c.first-b.first;
    long long v2 = c.second-b.second;
    long long tmp = u1*v2-u2*v1;

    return ((tmp>0) ? 1 : (tmp<0) ? -1 : 0);
}