// http://icpc.me/15688
#include <bits/stdc++.h>

using namespace std;

int arr[2'000'001]; // -1 000 000 ~ 1 000 000

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;

        ++arr[temp+1'000'000];
    }

    for (int i = 0; i<=2'000'000; ++i) {
        while (arr[i]--) {
            cout << i - 1'000'000 << '\n';
        }
    }

    return 0;
}
