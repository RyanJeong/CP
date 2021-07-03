// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;
        pq.push(temp);
    }

    vector<int> v(n);
    v.reserve(n);
    for (int i = 0; i<n; ++i) {
        v[i]=pq.top();
        pq.pop();
    }
    for (int i : v) {
        cout << i << '\n';
    }

    return 0;
}