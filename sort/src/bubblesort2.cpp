// https://www.acmicpc.net/submit/2751
// O(n^2)
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

	// bubble sort
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n-1-i; ++j) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
			}
		}
	}
	for (int i = 0; i<n; ++i) {
		cout << arr[i] << '\n';
	}

	return 0;
}