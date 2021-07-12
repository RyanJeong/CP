// https://www.acmicpc.net/problem/2239
#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
int row_cond[9]; // sum by row is 45
int col_cond[9]; // sum by col is 45
int sqr_cond[3][3]; // sum by sqr

void bt(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i = 0; i<9; ++i) {
		for (int j = 0; j<9; ++j) {
			char c;
			cin>>c;
			arr[i][j]=c-'0';
			row_cond[i]+=arr[i][j];
			col_cond[j]+=arr[i][j];
			sqr_cond[i/3][j/3]+=arr[i][j];
		}
		cin.ignore();
	}
	

	return 0;
}