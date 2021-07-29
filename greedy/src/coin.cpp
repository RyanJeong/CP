// https://www.acmicpc.net/problem/11047
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 할 때,
    // 필요한 동전 개수의 최솟값을 구하라.

    // 가치가 높은 동전을 우선 사용하면, 필요한 동전 개수를
    // 최소로 할 수 있다. 
    // K 값이 600원이고, 주어진 동전 종류가 100원, 500원 두 가지
    // 가치가 낮은 동전을 우선 사용한다면, 100원 짜리 동전이
    // 6개 필요하다. 
    // 가치가 높은 동전을 우선 사용한다면, 500원 짜리 동전 하나와
    // 100원 짜리 동전 하나, 총 2개가 필요하다. 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> coin(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>coin[i];
    }
    int res = 0;
    for (int i = n; i>0; --i) {
        res+=k/coin[i];
        k%=coin[i];
    }
    cout << res;

    return 0;
}