// https://www.acmicpc.net/problem/11729
#include <bits/stdc++.h>

using namespace std;

void move(int, int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;
    // 2^n-1
    cout << (1<<k)-1 << '\n';
    move(1,3,k);

    return 0;
}

void move(int from, int to, int n)
{
    if (n==1) {
        cout << from << ' ' << to << '\n';
    } 
    //a+b+c=6
    else {
        move(from,6-from-to,n-1);
        cout << from << ' ' << to << '\n';
        move(6-from-to,to,n-1);
    }

    return;
}
