// https://www.acmicpc.net/problem/2003
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int arr[10'000];
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    int low = 0;
    int high = 0;
    int res = 0;
    int sum = 0;
	while (low<=high) {
        if (sum>m) {
            sum-=arr[low++];
        } 
		else {
            if (sum==m) {
				++res;
			}
			// 0 1 2 3 '4'
			// if high point to '4' -> break!
			if (high==n) {
				break;
			}
            sum+=arr[high++];
		}
	}
    cout << res;

    return 0;
}