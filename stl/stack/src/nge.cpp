// https://www.acmicpc.net/problem/17298
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v;
    for (int i = 1; i<=n; ++i) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> res(v.size(),-1);
    stack<int> s;
    for (int i = 0; i<v.size(); ++i) {
        while (!s.empty() && v[s.top()]<v[i]) {
            res[s.top()]=v[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i : res) {
        cout << i << ' ';
    }

    return 0;
}