// https://www.acmicpc.net/problem/11758
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int x1, y1;
	cin>>x1>>y1;
	int x2, y2;
	cin>>x2>>y2;
	int x3, y3;
	cin>>x3>>y3;

	// u1v2-u2v1
	int u1 = x2-x1;
	int v1 = y2-y1;
	int u2 = x3-x2;
	int v2 = y3-y2;
	int tmp = u1*v2-u2*v1;
	cout << ((tmp>0) ? 1 : ((tmp<0) ? -1 : 0));

	return 0;
}