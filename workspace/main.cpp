// https://www.acmicpc.net/problem/2166
#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> Point;

long long outer_product(Point, Point);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<Point> v;
    for (int i = 1; i<=n; ++i) {
        long long x, y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    double res;
    for (int i = 1; i<n-1; ++i) {
        Point p1, p2;
        p1.first = v[i].first-v[0].first;
        p1.second = v[i].second-v[0].second;
        p2.first = v[i+1].first-v[0].first;
        p2.second = v[i+1].second-v[0].second;
        double tmp = (double) outer_product(p1,p2)/2.0;
        res+=tmp;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(res);

    return 0;
}

long long outer_product(Point u, Point v)
{

    return u.first*v.second-u.second*v.first;
}

