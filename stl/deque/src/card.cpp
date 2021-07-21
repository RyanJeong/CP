// https://www.acmicpc.net/problem/18115
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    stack<int> s;
    for (int i = 1; i<=n; ++i) {
        int c;
        cin>>c;
        s.push(c);
    }

    deque<int> dq;
    for (int i = 1; i<=n; ++i) {
        if (s.top()==1) {
            dq.push_front(i);
        }
        else if (s.top()==2) {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_front(i);
            dq.push_front(tmp);
        }
        else { // 3
            dq.push_back(i);
        }
        s.pop();
    }
    for (int i : dq) {
        cout << i << ' ';
    }

    return 0;
}