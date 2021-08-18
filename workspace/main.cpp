<<<<<<< HEAD
/*
배열 요소들의 합 비교 시 아래 케이스는 통과할 수 없음:
2
1 2
2 1
1 0
0 1
2 1
1 2
*/
=======
// https://www.acmicpc.net/problem/2166
>>>>>>> 0eca525590ce7aab6fd898c1cf235ad6b9605664
#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
=======
typedef pair<long long, long long> Point;

long long outer_product(Point, Point);

>>>>>>> 0eca525590ce7aab6fd898c1cf235ad6b9605664
int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
<<<<<<< HEAD

    long long mod = 1e9+7;
    int n;
    cin>>n;
    vector<vector<long long>> a(n,vector<long long>(n));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            cin>>a[i][j];
        }
    }
    vector<vector<long long>> b(n,vector<long long>(n));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            cin>>b[i][j];
        }
    }
    vector<vector<long long>> c(n,vector<long long>(n));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            cin>>c[i][j];
        }
    }
=======

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
>>>>>>> 0eca525590ce7aab6fd898c1cf235ad6b9605664

    // Freivalds' algorithm
    // ABr == Cr
    srand(time(0));
    int it = 20;
    bool is_same = true;
    while (--it && is_same) {
        vector<long long> r(n);
        for (long long& e : r) {
            e=rand()%2;
        }

<<<<<<< HEAD
        vector<long long> br(n);
        /* overflow may occer :
        br[i]=inner_product(r.begin(),r.end(),b[i].begin(),0);
        */
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                br[i]=(br[i]+(b[i][j]*r[j]))%mod;
            }
        }

        vector<long long> abr(n);
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                // worst case: 10e9+6 + 10e9+6*10e9+6 <= LONG_LONG_MAX_VAL
                abr[i]=(abr[i]+(a[i][j]*br[j]))%mod;
            }
        }

        for (int i = 0; i<n; ++i) {
            long long cr_row = 0;
            for (int j = 0; j<n; ++j) {
                cr_row=(cr_row+(c[i][j]*r[j]))%mod;
            }
            if (abr[i]!=cr_row) {
                is_same=false;
                break;
            }
        }
    }
    cout << ((is_same) ? "YES" : "NO");

    return 0;
}
=======
long long outer_product(Point u, Point v)
{

    return u.first*v.second-u.second*v.first;
}

>>>>>>> 0eca525590ce7aab6fd898c1cf235ad6b9605664
