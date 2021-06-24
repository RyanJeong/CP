//http://icpc.me/2251
#include <bits/stdc++.h>

using namespace std;

void dfs(int, int, int);

vector<int> answer;
bool is_checked[201][201];
int a, b, c;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>a>>b>>c;

	dfs(0,0,c);
	sort(answer.begin(),answer.end());
	for (int i : answer) {
		cout << i << ' ';
	}

	return 0;
}

void dfs(int cur_a, int cur_b, int cur_c)
{
	if (is_checked[cur_a][cur_b]) {
		
		return;
	}
	is_checked[cur_a][cur_b]=true;
	if (!cur_a) {
		answer.push_back(cur_c);
	}

	// from a to b
	if (cur_a>b-cur_b) {
		dfs(cur_a-(b-cur_b),b,cur_c);
	}
	else {
		dfs(0,cur_a+cur_b,cur_c);
	}

	// from b to a
	if (cur_b>a-cur_a) {
		dfs(a,cur_b-(a-cur_a),cur_c);
	}
	else {
		dfs(cur_a+cur_b,0,cur_c);
	}

	// from b to c (cur_a+cur_b+cur_c==c)
	dfs(cur_a,0,cur_b+cur_c);

	// from c to b
	if (cur_c>b-cur_b) {
		dfs(cur_a,b,cur_c-(b-cur_b));
	}
	else {
		dfs(cur_a,cur_b+cur_c,0);
	}

	// from a to c (cur_a+cur_b+cur_c==c)
	dfs(0,cur_b,cur_a+cur_c);

	// from c to a
	if (cur_c>a-cur_a) {
		dfs(a,cur_b,cur_c-(a-cur_a));
	}
	else {
		dfs(cur_a+cur_c,cur_b,0);
	}
	return;
}