// https://www.acmicpc.net/problem/2580
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int> v;

	for (int i = 1; i<=5; ++i) {
		v.push_back(i);
		cout << '[' << &v.front() << ']' << "cap: " << v.capacity() << ", len: " << v.size() << ": ";
		for (int j : v) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i<=5; ++i) {
		v.pop_back();
		cout << '[' << &v.front() << ']' << "cap: " << v.capacity() << ", len: " << v.size() << ": ";
		for (int j : v) {
			cout << j << ' ';
		}
		cout << '\n';
	}

    return 0;
}