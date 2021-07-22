// https://programmers.co.kr/learn/courses/30/lessons/42626
// 더 맵게
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : scoville) {
        pq.push(i);
    }
    int answer = 0;
    while (pq.top()<K) {
        if (pq.size()<2) {
            
            return -1;
        }
        int a = pq.top(); 
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b*2);
        ++answer;
    }

    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> s(n);
    for (int i = 0; i<n; ++i) {
        cin>>s[i];
    }
    int k;
    cin>>k;
    cout << solution(s,k);

    return 0;
}