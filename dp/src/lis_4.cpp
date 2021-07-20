// https://www.acmicpc.net/problem/14002
// v, len은 1-based, lis는 0-based임
// lis는 실제 요소의 개수가 가장 긴 증가하는 부분 수열의 크기이므로, 0-based를 사용해야 함
// cur-lis.size()+1을 해준 이유는, lis가 0-based이기 때문
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }

    vector<int> lis; // 0-based
    lis.push_back(v[1]); 
    vector<int> len(1);  // 1-based
    len.push_back(1);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
            len.push_back(lis.size());
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
            len.push_back(cur-lis.begin()+1); // 0-based
        }
    }
    int target = lis.size();
    cout << target << '\n';
    stack<int> s;
    for (int i = n; i>0; --i) {
        if (len[i]==target) {
            s.push(v[i]);
            --target;
        }
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
