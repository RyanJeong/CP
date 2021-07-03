// https://www.acmicpc.net/problem/1655
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 1; i<=n; ++i) {
        int temp;
        cin>>temp;
        if (max_heap.size()<=min_heap.size()) {
            max_heap.push(temp);
        }
        else {
            min_heap.push(temp);
        }
        if (!max_heap.empty() && !min_heap.empty() && max_heap.top()>min_heap.top()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        cout << max_heap.top() << '\n';
    }

    return 0;
}