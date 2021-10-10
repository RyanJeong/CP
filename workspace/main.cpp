#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	s.push_back(',');

	vector<int> v;
	int tmp = 0;
	int sign = 1;
	for (char c : s) {
		if (c==',') {
			v.push_back(sign*tmp);
			tmp=0;
			sign=1;
		}
		else if (c=='-') {
			sign*=-1;
		}
		else {
			tmp=tmp*10+c-'0';
		}
	}

	for (int i = 0; i<k; ++i) {
		for (int j = 0; j<n-i-1; ++j) {
			v[j]=v[j+1]-v[j];
		}
	}	
	for (int i = 0; i<n-k; ++i) {
		cout << v[i] << ((i==n-k-1) ? "" : ",");
	}
	
	return 0;
}