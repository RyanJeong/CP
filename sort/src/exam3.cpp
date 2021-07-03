// C++ implementation of Counting Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // k : 1 ~ 200
    int arr[] = {174,84,75,22,123,24,2,78};
    int freq[1+200]; // 0, 1 ~ k
    memset(freq,0,sizeof freq);

    // n times
    for (int i : arr) {
        ++freq[i];
    }
    // k times + n times
    // when for-statement completes k iterations, 
    // while-loop executes a total of n operations
    // => 2n + k, O(n + k)
    for (int i = 1; i<=200; ++i) {
        // 
        while (freq[i]--) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}