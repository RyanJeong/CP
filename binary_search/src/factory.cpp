// https://www.acmicpc.net/problem/16472
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }

    int low = 1;
    int high = n+1; // [low,high)
    while (low<high) {
        int mid = (low+high)/2;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i<mid; ++i) {
            pq.push(0);
        }
        bool is_possible = true;
        for (int i = 0; i<n; ++i) {
            auto cur = pq.top();
            pq.pop();
            if (cur+v[i]>x) {
                is_possible=false;
                break;
            }
            pq.push(cur+v[i]);
        }

        if (!is_possible) {
            low=mid+1;
        }
        else {
            high=mid;
        }
    }
    cout << high;

    return 0;
}
