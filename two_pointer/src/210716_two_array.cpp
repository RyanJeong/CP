// https://www.acmicpc.net/problem/2143
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i<n; ++i) {
		cin>>a[i];
	}
	int m;
	cin>>m;
	vector<int> b(m);
	for (int i = 0; i<m; ++i) {
		cin>>b[i];
	}

	for (int i = 0; i<n; ++i) {
		int tmp = a[i];
		for (int j = i+1; j<n; ++j) {
			tmp+=a[j];
			a.push_back(tmp);
		}
	}
	for (int i = 0; i<m; ++i) {
		int tmp = b[i];
		for (int j = i+1; j<m; ++j) {
			tmp+=b[j];
			b.push_back(tmp);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	// 500,500 x 500,500
	long long res = 0;
	for (int i = 0; i<a.size(); ++i) {
		auto low = lower_bound(b.begin(),b.end(),t-a[i]);
		auto high = upper_bound(b.begin(),b.end(),t-a[i]);
		res+=high-low;
	}
	cout << res;

	return 0;
}