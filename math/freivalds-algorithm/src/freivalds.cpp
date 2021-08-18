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
        // set r
        vector<long long> r(n);
        for (long long& e : r) {
            e=rand()%2;
        }

        // get Br
        vector<long long> br(n);
        /* overflow may occer :
        br[i]=inner_product(r.begin(),r.end(),b[i].begin(),0);
        */
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                br[i]=(br[i]+(b[i][j]*r[j]))%mod;
            }
        }

        // get ABr
        vector<long long> abr(n);
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                // worst case: 10e9+6 + 10e9+6*10e9+6 <= LONG_LONG_MAX_VAL
                abr[i]=(abr[i]+(a[i][j]*br[j]))%mod;
            }
        }

        // compare between ABr and Cr
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