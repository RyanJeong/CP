// http://icpc.me/2501
#include <bits/stdc++.h>

using namespace std;

vector<int> divisor(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    vector<int> v(divisor(a)); // ascending order
    int size = v.size();

    cout << ((size < b) ? 0 : v[b-1]);

    return 0;
}

vector<int> divisor(int n)
{
    vector<int> ret;

    for (int i = 1; i*i<=n; ++i) {
        if (!(n%i)) {
            ret.push_back(i);
        }
    }
    int size = ret.size();

    for (int i = size - 1; i>=0; --i) {
        if (ret[i]*ret[i]==n) {
            continue;
        }
        ret.push_back(n/ret[i]);
    }

    return ret;
}