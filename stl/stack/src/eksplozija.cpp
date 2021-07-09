// https://www.acmicpc.net/problem/9935
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string s, t;
	cin>>s>>t;
	string res;
	for (char c : s) {
		res.push_back(c);
		if (c==t.back()) {
			if (res.size()<t.size()) {
				continue;
			}
			bool is_same = true;	
			for (int i = 1; i<=t.size(); ++i) {
				if (res[res.size()-i]!=t[t.size()-i]) {
					is_same=false;
					break;
				}
			}
			if (is_same) {
				for (int i = 0; i<t.size(); ++i) {
					res.pop_back();
				}
			}
		}
	}
	cout << ((res.empty()) ? "FRULA" : res);

	return 0;
}
