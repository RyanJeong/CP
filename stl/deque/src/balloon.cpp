// https://www.acmicpc.net/problem/2346
// 풍선 터뜨리기
// 양수(오른쪽 이동) -> 맨 앞 요소를 맨 뒤로 옮긴 뒤 맨 뒤 요소 참조
// 음수(왼쪽 이동) -> 맨 뒤 요소를 맨 앞으로 옮긴 뒤 맨 뒤 앞 참조

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // index, op
    deque<pair<int, int>> dq;
    for (int i = 1; i<=n; ++i) {
        int tmp;
        cin>>tmp;
        dq.push_back({i,tmp});
    }
    
    auto cur = dq.front();
    dq.pop_front();
    cout << cur.first << ' ';
    while (!dq.empty()) {
        if (cur.second>0) {
            while (cur.second--) {
                dq.push_back(dq.front());
                dq.pop_front();        
            }
            cur=dq.back();
            dq.pop_back();
        }
        else {
            while (cur.second++) {
                dq.push_front(dq.back());
                dq.pop_back();        
            }
            cur=dq.front();
            dq.pop_front();
        }
        cout << cur.first << ' ';
    }

    return 0;
}
