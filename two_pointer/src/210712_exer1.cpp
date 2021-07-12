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

    int res = 0;
	for (int i = 0; i<n; ++i) {
		int sum = 0;
		for (int j = i; j<n; ++j) {
			sum+=arr[j];
			if (sum==m) {
				++res;
			}
			else if (sum>m) {
				break;
			}
		}
	}
    cout << res;

    return 0;
}
