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
		// 만약 지뢰를 사용하게 된다면 
		// 공격 가능한 범위에 속한 나머지 좀비들은
		// 공격을 한 회 덜 받게 된다.
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
				// 지뢰를 사용해 공격을 덜 받는
				// 마지막 인덱스를 값으로 queue에 삽입
				mine.push(i+r-1);
				--c;
			}
			else {
				// 지뢰를 사용해야 하는 상황에서
				// 지뢰가 더 이상 없을 경우
				is_survived=false;
				break;
			}
		}
	}
	cout << ((is_survived) ? "YES" : "NO");

	return 0;
}