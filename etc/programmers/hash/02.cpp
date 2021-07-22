// https://programmers.co.kr/learn/courses/30/lessons/42577
// 전화번호 목록
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
    // 문자열의 사전 순 정렬 결과를 생각해 보라.
    sort(phone_book.begin(),phone_book.end());
    for (int i = 1; i<phone_book.size(); ++i) {
        if (phone_book[i-1].size()>phone_book[i].size()) {
            continue;
        }
        if (phone_book[i-1]==phone_book[i].substr(0,phone_book[i-1].size())) {

            return false;
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