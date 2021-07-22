// https://programmers.co.kr/learn/courses/30/lessons/42586
// 기능개발
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    queue<pair<int, int>> q;
    int size = progresses.size();
    for (int i = 0; i<size; ++i) {
        q.push({progresses[i],speeds[i]});
    }

    vector<int> answer;
    int cnt;
    while (!q.empty()) {
        cnt=q.size();
        int num = 0;
        while (cnt--) {
            if (q.front().first>=100) {
                q.pop();
                ++num;
            }
            else {
                break;
            }
        }
        if (num) {
            answer.push_back(num);
        }

        cnt=q.size();
        while (cnt--) {
            auto cur = q.front();
            q.pop();
            q.push({cur.first+cur.second,cur.second});

        }
    }

    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> p(n);
        for (int i = 0; i<n; ++i) {
            cin>>p[i];
        }
        vector<int> s(n);
        for (int i = 0; i<n; ++i) {
            cin>>s[i];
        }
        for (auto i : solution(p,s)) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}