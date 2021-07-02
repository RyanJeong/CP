#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	v.push_back(3);
	v.push_back(-2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(-1);

	// non-descending order
	sort(v.begin(),v.end()); // default comparison (operator <)
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	// descending order
	sort(v.begin(),v.end(),greater<int>()); // the standard library compare function object
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	// non-descending order
	sort(v.begin(),v.end(),less<int>()); // the standard library compare function object
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}