// https://www.acmicpc.net/problem/6194
#include <bits/stdc++.h>

using namespace std;

pair<int, int> start;

bool cmp_coor(const pair<int, int>&, const pair<int, int>&);
bool cmp_ccw(const pair<int, int>&, const pair<int, int>&);
long long ccw(const pair<int, int>&, 
    const pair<int, int>&, 
    const pair<int, int>&);

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

    vector<pair<int, int>> buf;
    buf.push_back(v[0]); // start
    buf.push_back(v[1]);
    for (int i = 2; i<n; ++i) {
        while (buf.size()>=2) {
            pair<int, int> p1, p2;
            p2=buf.back();
            buf.pop_back();
            p1=buf.back();
            if (ccw(p1,p2,v[i])>0) {
                buf.push_back(p2);
                break;
            }
        }
        buf.push_back(v[i]);
    }

    buf.push_back(buf.front());
    double res = 0.0;
    for (int i = 0; i<buf.size()-1; ++i) {
        double d_x = (double) buf[i+1].first-(double) buf[i].first;
        double d_y = (double) buf[i+1].second-(double) buf[i].second;
        res+=sqrt(d_x*d_x+d_y*d_y);
    }
    cout << fixed;
    cout.precision(2);
    cout << res;

    return 0;
}

bool cmp_coor(const pair<int, int>& s, const pair<int, int>& t)
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

// -deg(ccw) ~ deg(cw)
bool cmp_ccw(const pair<int, int>& s, const pair<int, int>& t)
{
    long long cond = ccw(start,s,t);
    if (cond) {

        return cond>0; // pos: ccw, neg: cw
    }
    else {
        // x1==x2 or y1==y2

        return s.first+s.second<t.first+t.second;
    }
}

// ccw         : 1
// on the line : 0
// cw          : -1
long long ccw(const pair<int, int>& a, 
    const pair<int, int>& b, 
    const pair<int, int>& c)
{
    long long u1 = b.first-a.first;
    long long v1 = b.second-a.second;
    long long u2 = c.first-a.first;
    long long v2 = c.second-a.second;

    return u1*v2-u2*v1;
}
