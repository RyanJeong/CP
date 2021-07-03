// https://www.acmicpc.net/problem/2075
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;
    const int size = n*n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i<size; ++i) {
        int temp;
        cin>>temp;
        pq.push(temp);
        if (pq.size()>n) {
            pq.pop();
        }
    }
    cout << pq.top();

	return 0;
}