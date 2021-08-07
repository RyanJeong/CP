#include <bits/stdc++.h>

using namespace std;

/*
    {1 2 3 4}, n = 4, k = 9 => {2 3 1 4}
    idx: k/(n-1)!, next k: k%(n-1)!
    1) n = 4
       k/(n-1)! = 1, k%(n-1)! = 3, idx: 1, n = 3, k = 3
       {2}, {1 3 4}
    2) n = 3
       k/(n-1)! = 1, k%(n-1)! = 1, idx: 1, n = 2, k = 1
       {2 3} {1 4}
    3) n = 2
       k/(n-1)! = 1, k%(n-1)! = 0
       next k가 0이면, idx를 1 감소하고 next k를 (n-1)!로 지정
       idx: 0, n = 1, k = 1
       {2 3 1} {4}
    4) n = 1
       k/(n-1)! = 1, k%(n-1)! = 0
       next k가 0이면, idx를 1 감소하고 next k를 (n-1)!로 지정
       idx: 0, n = 0, k = 1
*/
vector<int> solution(int n, long long k) 
{
    vector<int> v;
    for (int i = 1; i<=n; ++i) {
        v.push_back(i);
    }
    vector<long long> fact(1,1);
    for (int i = 1; i<n; ++i) {
        fact.push_back(fact[i-1]*i);
    }

    vector<int> answer;
    while (n--) {
        int idx = k/fact[n];
        k%=fact[n];
        if (k==0) {
            --idx;
            k=fact[n];
        }

        answer.push_back(v[idx]);
        v.erase(v.begin()+idx);
    }

    return answer;
}