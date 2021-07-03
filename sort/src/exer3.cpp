// C++ implementation of Radix Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {-25, 2, 56, 234, 563246, -14325, 2345, -2345};
    int n = sizeof arr/sizeof(int);

    // Radix Sort
    // use 8-bit as radix
    for (int b = 0; b<4; ++b) {
        vector<int> v[256];
        for (int i = 0; i<n; ++i) {
            int idx = (arr[i]>>8*b)&0xFF;
            v[idx].push_back(arr[i]);
        }
        // included a sign bit
        if (b==3) {
            for (int i = 0; i<128; ++i) {
                vector<int> temp=v[i+128];
                v[i+128]=v[i];
                v[i]=temp;
            }
        }
        int i = 0;
        for (int idx = 0; idx<256; ++idx) {
            for (auto elem : v[idx]) {
                arr[i++]=elem;
            }
        }
    }
    for (int i : arr) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
