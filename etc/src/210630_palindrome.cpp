// https://www.acmicpc.net/problem/1254
#include <bits/stdc++.h>

using namespace std;

void dfs(int, int, int);


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string str;
	cin>>str;
	int add = 0;
	while (1) {
		int i = add;
		int j = str.size()-1;
		if (i==j) {
			break;
		}
		while (i<j) {
			if (str[i]!=str[j]) {
				break;
			}
			++i;
			--j;
		}
		if (i<j) {
			++add;
		}
		else {
			break;
		}
	}
	cout << str.size()+add;

	return 0;
}
