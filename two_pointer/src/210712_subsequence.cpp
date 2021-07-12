// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int arr[100'000];
    int n, s;
    cin>>n>>s;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    int low = 0;
    int high = 0;
    int len = 100'001;
    int sub = 0;
	while (low<=high) {
        if (sub>s) {
			len=min(len,high-low);
            sub-=arr[low++];
        } 
		else {
			if (sub==s) {
				len=min(len,high-low);
			}
			if (high==n) {
				break;
			}
            sub+=arr[high++];
		}
	}
    cout << ((len==100'001) ? 0 : len);

    return 0;
}
