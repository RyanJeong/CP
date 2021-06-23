// http://icpc.me/1021
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    int n, m;
    cin>>n>>m;
    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
        dq.push_back(i);
    }

    while (m--) {
        int index;
        int num;
        cin>>num;

        for (int i = 0; i<dq.size(); ++i) {
            if (num==dq[i]) {
                index=i;
                break;
            }
        }
        while (1) {
            if (num==dq.front()) {
                dq.pop_front();
                break;
            }
            else {
                ++count;
                if (index*2<dq.size()) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                } 
                else {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    cout << count;

    return 0;
}