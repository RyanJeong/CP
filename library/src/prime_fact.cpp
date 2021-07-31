// https://www.acmicpc.net/problem/11653
// 소인수분해
#include <bits/stdc++.h>

using namespace std;

void prime_factorization(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    prime_factorization(n);

    return 0;
}

void prime_factorization(int n)
{
    for (int i = 2; i*i<=n; ++i) { // 1 is not a prime number
        while (n%i==0) {
            cout << i << '\n';
            n/=i;
        }
    }
    if (n>1) {
        cout << n; 
    }

    return;
}