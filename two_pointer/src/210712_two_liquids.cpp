// https://www.acmicpc.net/problem/14921
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int arr[100'000];
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    int low = 0;
    int high = n-1;
	int target = 200'000'000;
	while (low<high) {
		int tmp = arr[low]+arr[high];
		if (abs(target)>abs(tmp)) {
			target=tmp;
		}
		if (tmp<0) {
			++low;
		}
		else if (tmp>0) {
			--high;
		}
		else {
			break;
		}
	}
    cout << target;

    return 0;
}