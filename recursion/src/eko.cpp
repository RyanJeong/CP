// https://www.acmicpc.net/problem/2805
#include <bits/stdc++.h>

using namespace std;

void rec(int, int, int); // low, high, target

vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    v=vector<int>(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    rec(0,v.back(),m);

    return 0;
}

void rec(int low, int high, int target)
{
    if (low>high) {
        cout << high;

        return;
    }
    int mid = (low+high)/2;
    long long total = 0;
    for (int t : v) {
        if (t>mid) {
            total+=t-mid;
        }
    }
    if (total==target) {
        cout << mid;

        return;
    }
    else if (total>target) {
        rec(mid+1,high,target);
    }
    else {
        rec(0,mid-1,target);
    }
}