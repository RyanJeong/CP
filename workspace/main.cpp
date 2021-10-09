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

    int res = abs(n-100);
    for (int i = 0; i<1'000'000; ++i) {
        int cnt = 0;
        int ch = i;
        do {
            if (is_broken[ch%10]) {
                cnt=0;
                break;
            }
            ++cnt;
            ch/=10;
        } while (ch>0);
        
        if (cnt>0) {
            cnt+=abs(n-i);
            res=min(res,cnt);
        }
    }

    cout << res;

    return 0;
}