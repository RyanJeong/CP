// https://programmers.co.kr/learn/courses/30/lessons/42577
// 전화번호 목록
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
    vector<pair<int, string>> v;
    for (auto str : phone_book) {
        v.push_back({str.size(),str});
    }
    sort(v.begin(),v.end(),greater<pair<int, string>>());
    while (!v.empty()) {
        auto cur = v.back();
        v.pop_back();
        for (auto elem : v) {
            if (cur.second==elem.second.substr(0,cur.first)) {
                
                return false;
            }
        }
    }

    return true;
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
        vector<string> p(n);
        for (int i = 0; i<n; ++i) {
            cin>>p[i];
        }
        cout << solution(p) << '\n';
    }

    return 0;
}