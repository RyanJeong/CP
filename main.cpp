// https://www.acmicpc.net/problem/19640
#include <bits/stdc++.h>

using namespace std;

struct Elem {
	int _d;
	int _h;
	int _l;
	bool _is_deca;
};

struct Cmp {
	bool operator()(Elem s, Elem t) 
	{
		if (s._d>t._d) {

			return true;
		}
		else if (s._d==t._d && s._h>t._h) {

			return true;
		}
		else if (s._d==t._d && s._h==t._h && s._l<t._l) {

			return true;
		}
		else {

			return false;
		}
	}
};

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m, k;
	cin>>n>>m>>k;
	queue<Elem> q[m+1];
	for (int i = 1; i<=n; ++i) {
		int d, h;
		cin>>d>>h;
		int line = ((i%m) ? i%m : m);
		q[line].push({d,h,line,((k--) ? false : true)});
	}

	priority_queue<Elem, vector<Elem>, Cmp> pq;
	for (int i = 1; i<=m; ++i) {
		if (!q[i].empty()) {
			auto cur = q[i].front();
			q[i].pop();

		}
	}


	return 0;
}