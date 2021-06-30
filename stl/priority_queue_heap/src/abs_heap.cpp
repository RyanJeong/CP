// https://www.acmicpc.net/problem/11286
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	priority_queue<pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>> min_heap;

	while (n--) {
		int x;
		cin >> x;

		if (!x) {
			if (min_heap.empty()) {
				cout << "0\n";
			} 
			else {
				cout << min_heap.top().second << '\n';
				min_heap.pop();
			}
		} 
		else {
			min_heap.push({abs(x),x});
		}
	}

	return 0;
}