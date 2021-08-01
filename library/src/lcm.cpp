/*
    A × B = GCD(A, B) × LCM(A, B) 
 -> A X B ÷ GCD(A, B) = LCM(A, B);
*/
#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    sort(v.begin()+1,v.end());
    for (int i = 1; i<n; ++i) {
        v[i+1]=lcm(v[i],v[i+1]);
    }
    cout << v[n];

    return 0;
}

int gcd(int a, int b)
{
    
    return ((b==0) ? a : gcd(b,a%b));
}

int lcm(int a, int b)
{
    
    return a/gcd(a,b)*b; // escape overflow
}