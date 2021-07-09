// https://www.acmicpc.net/problem/7785
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	set<string, greater<string>> s;
	while (n--) {
		string name, state;
		cin>>name>>state;
		if (state=="enter") {
			s.insert(name);
		}
		else { // leave
			if (s.find(name)!=s.end()) {
				s.erase(name);
			}
		}
	}
	for (string name : s) {
		cout << name << '\n';
	}

	return 0;
}