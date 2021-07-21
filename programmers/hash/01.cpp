// https://programmers.co.kr/learn/courses/30/lessons/42576
// 완주하지 못한 선수
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    map<string, int> m;
    for (auto str : participant) {
        ++m[str];
    }
    for (auto str : completion) {
        --m[str];
    }
    string answer;
    for (auto it : m) {
        if (it.second) {
            answer=it.first;
            break;
        }
    }
    
    return answer;
}

int main(void)
{
    int n;
    cin>>n;
    vector<string> p(n);
    for (int i = 0; i<n; ++i) {
        cin>>p[i];
    }
    int m;
    cin>>m;
    vector<string> c(m);
    for (int i = 0; i<m; ++i) {
        cin>>c[i];
    }
    cout << solution(p,c);

    return 0;
}

        
