#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int n, m, k;
	
	cin >> n >> m >> k;
	vector<int> v(n + m, 1);
	fill(v.begin(), v.begin() + n, 0);
	do {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}