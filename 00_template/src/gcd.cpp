#include <bits/stdc++.h>

using namespace std;

vector<int> getPrime(int n) 
{
    vector<int> primes;
    vector<bool> state(n+1,true); // 0, 1 ~ n

    state[1]=false;
    for (int i = 2; i*i<=n; ++i) {
        if (!state[i]) {
            continue;
        }

        for (int j = i*i; j<=n; j+=i) {
            state[j]=false;
        }
    }
    for (int i = 1; i<=n; ++i) {
        if (state[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = getPrime(289);

    for (int n : v) {
        cout << n << '\n';
    }

    return 0;
}