// comb. + dp + rec.
// http://icpc.me/1256
#include <bits/stdc++.h>

using namespace std;

long long comb(int n, int m);
void print(int n, int m, long long k);

/*
i 번째 a로 고정할 시, 
a의 갯수: n-1, z의 갯수: m
n-1+m C n-1 x m C m
=> n-1+m C n-1
*/
long long arr[205][105]; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    cin>>n>>m>>k;

    if (comb(n+m,n)<k) {
        cout << -1;
    } 
    else {
        print(n,m,k);
    }

    return 0;
}

// n C m
long long comb(int n, int m)
{
    if (n==m || m==0) {

        return 1;
    }
    if (arr[n][m]) {

        return arr[n][m]; // already calculated
    }

    long long sub1 = comb(n-1,m-1);
    long long sub2 = comb(n-1,m);

    if (sub1+sub2>1e9) {
        arr[n][m]=1e9;
    } 
    else {
        arr[n][m]=sub1+sub2;
    }

    return arr[n][m];
}

void print(int n, int m, long long k)
{
    if (n==0) {
        while (m--) {
            cout << 'z';
        }
    } 
    else if (m==0) {
        while (n--) {
            cout << 'a';
        }
    } 
    else {
        long long n_a = comb(n-1+m,n-1);

        if (k<=n_a) {
            cout << 'a';
            print(n-1,m,k);
        } 
        else {
            cout << 'z';
            print(n,m-1,k-n_a);
        }
    }

    return;
}