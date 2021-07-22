// https://programmers.co.kr/learn/courses/30/lessons/42840
// 모의고사
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers)
{
    // 5
    int a[] = {
        1,2,3,4,5
    };
    // 8
    int b[] = {
        2,1,2,3,2,4,2,5
    };
    // 10
    int c[] = {
        3,3,1,1,2,2,4,4,5,5
    };
    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    int size = answers.size();
    for (int i = 0; i<size; ++i) {
        cnt_a+=(a[i%5]==answers[i]) ? 1 : 0;
        cnt_b+=(b[i%8]==answers[i]) ? 1 : 0;
        cnt_c+=(c[i%10]==answers[i]) ? 1 : 0;
    }
    int cnt = max({cnt_a,cnt_b,cnt_c});
    vector<int> answer;
    if (cnt==cnt_a) {
        answer.push_back(1);
    }
    if (cnt==cnt_b) {
        answer.push_back(2);
    }
    if (cnt==cnt_c) {
        answer.push_back(3);
    }

    return answer;
}