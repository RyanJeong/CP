// https://www.acmicpc.net/problem/2473
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static long long arr[5'000];
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
	sort(arr,arr+n);

	long long target = 3'000'000'000;
	int l1, l2, l3;
	for (int low = 0; low<n-2; ++low) {
		int mid=low+1;
		int high=n-1;
		while (mid<high) {
			long long tmp = arr[low]+arr[mid]+arr[high];
			if (target>llabs(tmp)) {
				l1=arr[low];
				l2=arr[mid];
				l3=arr[high];
				target=llabs(tmp);
			}
			if (tmp<0) {
				++mid;
			}
			else if (tmp>0) {
				--high;
			}
			else {
				break;
			}
		}
	}
    cout << l1 << ' ' << l2 << ' ' << l3;

    return 0;
}