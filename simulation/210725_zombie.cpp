// https://www.acmicpc.net/problem/19644
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r, d, c;
    cin>>l>>r>>d>>c;
	bool is_survived = true;
	queue<int> mine;
	for (int i = 1; i<=l; ++i) {
		if (!mine.empty() && mine.back()<i) {
			mine.pop();
		}
		int hp;
		cin>>hp;
		if (i>r) {
			hp-=d*(r-mine.size());
		}
		else {
			hp-=d*(i-mine.size());
		}
		if (hp>0) {
			if (c>0) {
				mine.push(i+r-1);
				--c;
			}
			else {
				is_survived=false;
				break;
			}
		}
	}
	cout << ((is_survived) ? "YES" : "NO");

	return 0;
}