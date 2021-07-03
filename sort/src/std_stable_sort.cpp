// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    static int arr[1'000'000];
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    stable_sort(arr,arr+n);
    for (int i = 0; i<n; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}
