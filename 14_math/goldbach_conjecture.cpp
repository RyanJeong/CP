// http://icpc.me/6588
#include <bits/stdc++.h>

using namespace std;

vector<int> getPrime(int n) 
{
    vector<int> primes;
    vector<bool> state(n+1,true); // 0, 1 ~ n

    state[1]=false;
    for (long long i = 2; i*i<=n; ++i) {
        if (!state[i]) {
            continue;
        }
        for (long long j = i * i; j<=n; j+=i) {
            state[j] = false;
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

    vector<int> v = getPrime(1'000'000);
    int n;

    while (cin>>n) {
        if (!n) {
            break;
        }

        int low = 1;
        int high = 0;
        int size = v.size();

        while (low<=size) {
            high=low;
            while (high<=size) {
                if (v[low]+v[high]>=n) {
                    break;
                }
                ++high;
            }
            if (v[low]+v[high]==n) {
                break;
            } 
            else {
                ++low;
            }
        }

        if (v[low]+v[high]!=n) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        } 
        else {
            cout << n << " = " << v[low] << " + " << v[high] << '\n';
        }
    }

    return 0;
}
