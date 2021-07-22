// https://www.acmicpc.net/problem/2696
// max_heap   min_heap  middle
// (1)                  1
// (1)        (2)       1
// (3)<-(1)   (2)
// (2)<-(1)   (3)       2
// (2)<-(1)   (3)<-4    2
// ... 
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin>>p;
    while (p--) {
        int m;
        cin>>m;
        cout << m/2+1 << '\n';
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 1; i<=m; ++i) {
            int tmp;
            cin>>tmp;
            if (i&01) {
                max_heap.push(tmp);
                if (!min_heap.empty() && max_heap.top()>min_heap.top()) {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
                cout << max_heap.top() << ' ';
                if (max_heap.size()==10) {
                    cout << '\n';
                }
            }
            else {
                min_heap.push(tmp);
            }
        }
        cout << '\n';
    }

    return 0;
}
