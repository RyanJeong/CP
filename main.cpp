// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

void merge_sort(int, int);
void merge(int, int);

int arr[1'000];
int res[1'000];

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

	sort(arr,arr+n);
	for (int i = 0; i<n; ++i) {
		cout << arr[i] << '\n';
	}

	return 0;
}

void merge_sort(int s, int t)
{
	if (s+1==t) {
		
		return;
	}
	int mid = (s+t)/2;
	merge_sort(s,mid);
	merge_sort(mid,t);
	merge(s,t);
}

void merge(int s, int t)
{
	int mid = (s+t)/2;
	
	return;
}