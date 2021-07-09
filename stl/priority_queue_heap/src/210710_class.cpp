// https://www.acmicpc.net/problem/11000
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	// <from,to>
	vector<pair<int, int>> v;
	for (int i = 1; i<=n; ++i) {
		int s, t;
		cin>>s>>t;
		v.push_back({s,t});
	}

	sort(v.begin(),v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i<n; ++i) {
		auto cur = pq.top();
		if (v[i].first>=cur) {
			pq.pop(); // use the room
		}
		pq.push(v[i].second);
	}
	cout << pq.size();

	return 0;
}