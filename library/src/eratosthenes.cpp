// https://www.acmicpc.net/problem/1929
// 소수 구하기
#include <bits/stdc++.h>

using namespace std;

vector<int> eratosthenes_sieve(int from, int to) 
{
    static vector<bool> is_composition(to+1); // 1-based
    vector<int> primes;

    if (from<2) { // 1 is not a prime number
        from=2;
    }
    for (int i = 2; i*i<=to; ++i) {
        if (is_composition[i]) {
            continue;
        }
        for (int j = i*i; j<=to; j+=i) {
            is_composition[j]=true;
        }
    }
    for (int i = from; i<=to; ++i) {
        if (!is_composition[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;
    vector<int> v = eratosthenes_sieve(m,n);
    for (int i : v) {
        cout << i << '\n';
    }

    return 0;
}