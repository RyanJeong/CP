// http://icpc.me/16194
#include <bits/stdc++.h>

using namespace std;

int arr[1'005]; // 1 ~ 1,000, OOB
int price[1'005];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
	fill(arr + 1, arr + 1'005, 2e9);

	int n;
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> price[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			arr[i] = min(arr[i], arr[i-j] + price[j]);
		}
	}
	cout << arr[n];

	return 0;
}
