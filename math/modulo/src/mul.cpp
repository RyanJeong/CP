// https://www.acmicpc.net/problem/1629
#include <bits/stdc++.h>

using namespace std;

long long pow(long long, long long, long long);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin>>a>>b>>c;
    cout << pow(a,b,c);

    return 0;
}

long long pow(long long a, long long b, long long c)
{
    if (b==1) {

        return a%c;
    }

    long long val = pow(a,b/2,c);
    val = val*val%c;

    return (b&01) ? (val*a%c)%c : val;
}
