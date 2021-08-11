// https://programmers.co.kr/learn/courses/30/lessons/42587
// 프린터
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int>, int);

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
        int l;
        cin>>l;
        cout << solution(p,l) << '\n';
    }

    return 0;
}

int solution(vector<int> priorities, int location) 
{
    queue<pair<int, int>> q; // priority, index;
    vector<int> v; // priority
    for (int i = 0; i<priorities.size(); ++i) {
        q.push({priorities[i],i});
        v.push_back(priorities[i]);
    }
    sort(v.begin(),v.end(),greater<int>());
    int answer = 0;
    for (int p : v) {
        while (p!=q.front().first) {
            auto cur = q.front();
            q.pop();
            q.push(cur);
        }
        ++answer;
        if (location==q.front().second) {
            break;
        }
        q.pop();
    }

    return answer;
}