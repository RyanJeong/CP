// https://www.acmicpc.net/problem/1562
#include <bits/stdc++.h>

using namespace std;

int req(int, int, int);
const int mod(1e9);

int g_n;
vector<vector<vector<int>>> g_v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>g_n;;
    //v[g_n+1][10][1<<10];
    g_v=vector<vector<vector<int>>>(g_n+1,vector<vector<int>>(10,vector<int>(1<<10)));

    int res = 0;
    // 0으로 시작하는 수는 계단수가 아니다.
    for (int d = 1; d<10; ++d) {
        res=(res+req(1,d,1<<d))%mod;
    }
    cout << res; 

    return 0;
}

int req(int i, int d, int b)
{
    if (g_v[i][d][b]) {

        return g_v[i][d][b];
    }
    if (i==g_n) {

        return ((b==(1<<10)-1) ? 1 : 0);
    }
    if (d==0) { // 0->1
        g_v[i][d][b]=req(i+1,1,b|1<<1)%mod;
    }
    else if (d==9) { // 9->8
        g_v[i][d][b]=req(i+1,8,b|1<<8)%mod;
    }
    else { // n-1<-n->n+1
        g_v[i][d][b]=(req(i+1,d-1,b|1<<(d-1))+req(i+1,d+1,b|1<<(d+1)))%mod; 
    }

    return g_v[i][d][b];
}
