// https://www.acmicpc.net/problem/10651
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // No two cows in the same lane may ever occupy the same position.
    /* ex.
       3 3
       0 4 -> 12 (lane 1) 12
       1 3 -> 10 (lane 2) 12 10
       2 2 -> 8  (lane 3) 12 10 8
       => 3

       9 3
       0  1 -> 3  (lane 1) 3
       1  2 -> 7  (lane 1) 7
       2  3 -> 11 (lane 1) 11
       3  2 -> 9  (lane 2) 11 9
       6  1 -> 9  (lane 3) 11 9 9
       7  4 -> 21 (lane 1) 21 9 9
       8  3 -> 17 (lane 2) 21 17 9
       9  2 -> 15 (lane 3) 21 17 15
       10 2 -> 16 (lane 3) 21 17 16
       => 3

       -3     -> -3
       -7     -> -7
       -11    -> -11
       -9     -> -11 -9
       -9     -> -11 -9 -9
       -21    -> -21 -9 -9
       -17    -> -21 -17 -9
       -15    -> -21 -17 -15
       -16    -> -21 -17 -16
    */
    long long n, t;
    cin>>n>>t;

    vector<long long> lis;
    for (int i = 1; i<=n; ++i) {
        long long p, s;
        cin>>p>>s;
        p=-(p+s*t);

        if (lis.empty() || p>=lis.back()) {
            lis.push_back(p);
        }
        else {
            *upper_bound(lis.begin(),lis.end(),p)=p; // consider dup. cases
        }
    }
    cout << lis.size();

    return 0;
}