// https://www.acmicpc.net/problem/10453
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;

	while (t--) {
		string str1, str2;
		cin>>str1>>str2;

		int cnt = 0;
		int i = 0;
		while (i<str1.size()) {
			if (str1[i]==str2[i]) {
				continue;
			}
			int j = 0;
			while (i+j<str1.size()) {
				if (str1[i+j]==str2[i]) {
					char temp = str1[i+j];
					str1[i+j]=str2[i];
					str2[i]=temp;
					cnt+=j;
					break;
				}
				++j;
			}
			if (i+j==str1.size()) {
				break;
			}
			++i;
		}
	}

	return 0;
}