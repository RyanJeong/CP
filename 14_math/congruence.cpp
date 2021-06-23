/*
식 A ≡ B(mod m) 은 A와 B가 M으로 나눈 나머지가 같음을 의미

A ≡ B (mod m) 일 때
1. A + C ≡ B + C (mod m)
2. A - C ≡ B - C (mod m)
3. AC ≡ BC (mod m)
4. A ÷ C ≡ B ÷ C (mod m)은 성립하지 않음 ( A=6, B=2, C=2, M=4 )
*/
// http://icpc.me/6064
// A ≡ x (mod M), A ≡ y (mod N)
// -> (x + M | x + 2M | ... ) ≡ y (mod N)
#include <bits/stdc++.h>

using namespace std;

int solve(int m, int n, int x, int y);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
        int m, n, x, y;
        cin>>m>>n>>x>>y;

        cout << solve(m,n,x,y) << '\n';
    }

    return 0;
}

int solve(int m, int n, int x, int y)
{
    // search from the first possible case
    if (x==m) {
        x = 0;
    }
    if (y==n) {
        y = 0;
    }
    for (int i = x; i<=m*n; i+=m) {
        if (i%n==y) {
            
            return i;
        }
    }

    return -1;
}
