#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) 
{
    priority_queue<long long> pq;
    for (int i : works) {
        pq.push(i);
    }

    while (!pq.empty() && n--) {
        auto cur = pq.top();
        pq.pop();
        if (--cur>0) {
            pq.push(cur);
        }
    }

    long long answer = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        answer+=cur*cur;
    }

    return answer;
}