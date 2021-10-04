#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n;
        cin>>n;

        if (n==0) {
            break;
        }

        int res = 2;
        while (n) {
            int tmp = n%10;
            n/=10;
            switch (tmp) {
            case 1:
                res+=2;
                break;
            case 0:
                res+=4;
                break;
            default:
                res+=3;
                break;
            }

            if (n) {
                ++res;
            }

        }
        cout << res << '\n';
    }

    return 0;
}