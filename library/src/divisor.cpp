#include <bits/stdc++.h>

using namespace std;

vector<int> divisor(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i : divisor(n)) {
        cout << i << ' ';
    }

    return 0;
}

vector<int> divisor(int n)
{
    vector<int> divisors;
    for (int i = 1; i*i<=n; ++i) {
        if (n%i==0) {
            divisors.push_back(i);
        }
    }
    int size = divisors.size()-1;
    if (divisors.back()*divisors.back()==n) {
        --size; // 4*4=16
    }
    for (int i = size; i>=0; --i) {
        divisors.push_back(n/divisors[i]);
    }

    return divisors;
}