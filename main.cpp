// https://www.acmicpc.net/problem/12025
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin>>str;
	long long k;
	cin>>k;
	--k; // 1 -> 000, 2 -> 001, 3 -> 010, 4 -> 011
	for (auto it = str.rbegin(); it!=str.rend(); ++it) {
		char c = *it;
		if (c=='1' || c=='6') {
			c=(k&1)?'6':'1';	
			k>>=1;
		}
		else if (c=='2' || c=='7') {
			c=(k&1)?'7':'2';	
			k>>=1;
		}
		*it=c;
	}
	cout << ((k) ? "-1" : str);

	return 0;
}