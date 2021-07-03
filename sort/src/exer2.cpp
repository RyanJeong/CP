// https://www.acmicpc.net/problem/10989
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    static int freq[10'001];
    int low = 10'000;
    int high = 1;
    int n;
    cin>>n;
    // n times
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;
        ++freq[temp];
        low=min(low,temp);
        high=max(high,temp);
    }
    // k times + n times
    for (int i = low; i<=high; ++i) {
        while (freq[i]--) {
            cout << i << '\n';
        }
    }

    return 0;
}