// https://www.acmicpc.net/problem/1978
// 소수 찾기
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int cnt = 0;
    while (n--) {
        int tmp;
        cin>>tmp;
        cnt+=is_prime(tmp);
    }
    cout << cnt;

    return 0;
}

bool is_prime(int n)
{
    if (n==1) { // 1 is not a prime number

        return false;
    }
    for (int i = 2; i*i<=n; ++i) {
        if (n%i==0) { // none of the numbers 
                        // 2, 3, ... √n divides n evenly

            return false;
        }
    }

    return true;
}