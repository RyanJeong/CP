// http://icpc.me/12920
#include <bits/stdc++.h>

using namespace std;

int d[10'002]; // 0, 1 ~ 100,000, OOB
int v[10'002]; // 0, 1 ~ 100, OOB
int c[10'002]; // 0, 1 ~ 100, OOB

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m; // n, limit
    // v: weight, c: comf., k: n_object
    int alt_n = 0;

    for (int i = 1; i<=n; ++i) {
        int temp_v, temp_c, temp_k;
        cin>>temp_v>>temp_c>>temp_k;
        for (int mul = 1; temp_k>0; mul*=2) {
            // ex. 14 -> 1, 2, 4, 7
            int n_object = min(mul,temp_k);

            ++alt_n;
            v[alt_n]=temp_v*n_object;
            c[alt_n]=temp_c*n_object;
            temp_k-=n_object;
        }
    }
    for (int i = 1; i<=alt_n;++i) {
        int weight = v[i];
        int value = c[i];

        for (int j = m; j>=weight; --j) {
            d[j]=max(d[j],d[j-weight]+value);
        }
    }
    cout << d[m];

    return 0;
}