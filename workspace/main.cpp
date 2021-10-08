/*
// https://www.acmicpc.net/problem/1107
#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<bool> is_broken(10);
    while (m--) {
        int tmp;
        cin>>tmp;
        is_broken[tmp]=true;
    }

    int start = 100;
    int res = abs(n-start);

    cout << res;

    return 0;
}
*/