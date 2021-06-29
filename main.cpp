// https://www.acmicpc.net/problem/16922
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	const int add[] = {1,5,10,50};
	static bool is_used[50*20+1];
	int count = 0;
	int n;
	cin>>n;

	stack<pair<int, int>> s; // step, num
	s.push({0,0});
	while(!s.empty()) {
		auto cur = s.top();
		s.pop();

		int step = cur.first+1;
		int num = cur.second;
		if (step==n) {
			for (int i : add) {
				if (!is_used[num+i]) {
					++count;
					is_used[num+i]=true;
				}	
			}
		}
		else {
			for (int i : add) {
				s.push({step,num+i});
			}
		}
	}
	cout << count;

	return 0;
}