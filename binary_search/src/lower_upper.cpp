// http://icpc.me/10816
// lower_bound: key보다 크거나 같은 첫 번째 위치(이상)
// upper_bound: key보다 큰 첫 번째 위치(초과)
// ex, { 1, 3, 4, 4, 5 }
// key: 4 -> upper_bound(): 4, lower_bound(): 2
// key: 2 -> upper_bound(): 1, lower_bound(): 1 
#include <bits/stdc++.h>

using namespace std;

int arr[500005];

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin >> arr[i];
    } 
    int m;
    cin>>m;

    sort(arr,arr+n);
    while (m--) {
        int t;
        cin>>t;

        cout << upper_bound(arr,arr+n,t)-lower_bound(arr,arr+n,t) << ' ';
    }    

    return 0;
}