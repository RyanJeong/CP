#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> Point;

long long outer_product(Point u, Point v)
{

    return u.first*v.second-u.second*v.first;
}