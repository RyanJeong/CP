// https://www.acmicpc.net/problem/9465
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int arr[2][100'001];
	static int score[2][100'001];
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		for (int i = 0; i<2; ++i) {
			for (int j = 1; j<=n; ++j) {
				cin>>arr[i][j];
			}
		}
		score[0][1]=arr[0][1];
		score[1][1]=arr[1][1];
		for (int i = 2; i<=n; ++i) {
			score[0][i]=max(score[1][i-1],score[1][i-2])+arr[0][i];
			score[1][i]=max(score[0][i-1],score[0][i-2])+arr[1][i];
		}
		cout << max(score[0][n],score[1][n]) << '\n';
		memset(score,0,sizeof score);
	}

	return 0;
}