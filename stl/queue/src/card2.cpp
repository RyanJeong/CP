// https://www.acmicpc.net/problem/2164
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin>>n;
    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        q.push(i);
    }
    while (q.size()!=1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();

    return 0;
}