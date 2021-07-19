// https://www.acmicpc.net/problem/2565
// 교점 제거 -> LIS
// A를 기준으로 정렬한 뒤에, B를 기준으로 LIS를 구해보면 아래와 같다.
// A: 1 2 3 4 6 7 9 10
// B: 8 2 9 1 4 6 7 10
// LIS: {2,4,6,7,10} or {1,2,4,7,10}
// 전깃줄의 개수 중에 LIS의 개수를 빼면
// 전깃줄이 더이상 교차하지 않는다. 

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v(1); // 1-based
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int res = 1;
    vector<int> lis(n+1); // 1-based
    lis[1]=1;
    for (int i = 2; i<=n; ++i) {
        for (int j = 1; j<i; ++j) {
            if (v[i].second>v[j].second) {
                lis[i]=max(lis[i],lis[j]+1);
            }
            else {
                lis[i]=max(lis[i],1);
            }
        }
        res=max(res,lis[i]);
    }
    cout << n-res;

    return 0;
}
