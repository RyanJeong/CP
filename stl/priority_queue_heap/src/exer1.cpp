// https://www.acmicpc.net/problem/11279
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// https://en.cppreference.com/w/cpp/container/priority_queue 
	// priority_queue<int, vector<int>, greater<int>> -> min heap
	// priority_queue<int> -> max heap
	priority_queue<int> max_heap;

	while (n--) {
		int x;
		cin >> x;

		if (!x) {
			if (max_heap.empty()) {
				cout << "0\n";
			} 
			else {
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		} 
		else {
			max_heap.push(x);
		}
	}

	return 0;
}