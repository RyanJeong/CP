// http://icpc.me/1629
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

// b: 7 -> 3 -> 1 
// b: 9 -> 4 -> 2 -> 1
long long pow(long long a, long long b, long long c)
{
    if (b==1) {

        return a%c;
    }

    long long val = pow(a,b/2,c);
    val = val*val%c;

    // odd? b^2*a, else b^2
    return (b&01) ? val*a%c : val;
}