// https://www.acmicpc.net/problem/1708 
#include <bits/stdc++.h>

using namespace std;

pair<int, int> start;

bool cmp_coor(pair<int, int>, pair<int, int>);
bool cmp_ccw(pair<int, int>, pair<int, int>);
int is_ccw(pair<int, int>, pair<int, int>, pair<int, int>);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(),cmp_coor);
    start=v[0];
    sort(v.begin()+1,v.end(),cmp_ccw);

    stack<pair<int, int>> s;
    s.push(v[0]);
    s.push(v[1]);
    pair<int, int> p1, p2;
    for (int i = 2; i<n; ++i) {
        while (s.size()>=2) {
            p2=s.top();
            s.pop();
            p1=s.top();
            if (is_ccw(p1,p2,v[i])>0) {
                s.push(p2);
                break;
            }
        }
        s.push(v[i]);
    }
    cout << s.size();

    return 0;
}

bool cmp_coor(pair<int, int> s, pair<int, int> t)
{
    if (s.second<t.second) {

        return true;
    }
    else if (s.second==t.second && s.first<t.first) {

        return true;
    }
    else {

        return false;
    }
}

bool cmp_ccw(pair<int, int> s, pair<int, int> t)
{
    int cond = is_ccw(start,s,t);
    if (cond) {

        return cond>0; // pos: ccw, neg: cw
    }
    else {
        // x1==x2 or y1==y2

        return s.first+s.second<t.first+t.second;
    }
}

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