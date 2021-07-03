#include <bits/stdc++.h>

using namespace std;

bool cmp_less(int, int);
bool cmp_greater(int, int);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    v.push_back(3);
    v.push_back(-2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(-1);

    // non-descending order
    sort(v.begin(),v.end(),cmp_less); // default comparison (operator <)
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';

    // descending order
    sort(v.begin(),v.end(),cmp_greater); // the standard library compare function object
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}

bool cmp_less(int s, int t)
{

    return s<t;
}

bool cmp_greater(int s, int t)
{

    return s>t;
}