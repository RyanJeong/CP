// https://www.acmicpc.net/problem/11779
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
        vector<long long> br(n);
        for (int i = 0; i<n; ++i) {
            br[i]=inner_product(r.begin(),r.end(),b[i].begin(),0);
        }
        for (int i = 0; i<n; ++i) {
            /* overflow may occer :
            long long abr = inner_product(br.begin(),br.end(),a[i].begin(),(long long) 0)%mod;
            long long cr = inner_product(r.begin(),r.end(),c[i].begin(),(long long) 0)%mod;
            */
            long long abr = 0;
            for (int i = 0; i<n; ++i) {
                for (int j = 0; j<n; ++j) {
                    abr+=(a[i][j]*br[j])%mod;
                }
            }

            long long cr = 0;
            for (int i = 0; i<n; ++i) {
                for (int j = 0; j<n; ++j) {
                    cr+=(c[i][j]*r[j])%mod;
                }
            }

            if (abr!=cr) {
                is_same=false;
                break;
            }
        }
    }
    cout << ((is_same) ? "YES" : "NO");

    return 0;
}