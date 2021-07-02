// C++ implementation of Radix Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int arr[] = {174,84,75,22,723,24,2,78};
    int n = sizeof arr/sizeof(int);
	int max_n = 0;
	for (int i : arr) {
		max_n=max(max_n,i);	
	}

	// Radix Sort
	// the digit represented by d
	// l times
	for (int d = 1; max_n/d>0; d*=10) {
		vector<int> v[10];
		// n times
		for (int i = 0; i<n; ++i) {
			int idx = (arr[i]/d)%10;
			v[idx].push_back(arr[i]);
		}
		// k times
		int i = 0;
		for (int j = 0; j<10; ++j) {
			for (auto elem : v[j]) {
				arr[i++]=elem;
			}
		}
	}
	for (int i : arr) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}