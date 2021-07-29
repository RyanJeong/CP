// https://www.acmicpc.net/problem/2217
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 각 로프들에 대한 정보가 주어졌을 때, 
    // 이 로프들을 이용하여 들어올릴 수 있는 
    // 물체의 최대 중량을 구해내는 프로그램을 
    // 작성하라.

    // 가장 무거운 중량을 견디는 로프부터 
    // 하나씩 추가하여 로프들이 견디는
    // 최대 중량 계산

    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    sort(v.begin()+1,v.end(),greater<int>());
    int res=0;
    for (int i = 1; i<=n; ++i) {
        res=max(res,v[i]*i);
    }
    cout << res;

    return 0;
}
