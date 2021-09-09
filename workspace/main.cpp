#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3, m = 5;
    vector<bool> is_used1(m,false); // 0 0 0 0 0
    for (int i = 0; i<n; ++i) { // 1 1 1 0 0
        is_used1[i]=true;
    }
    do {
        for (auto i : is_used1) {
            cout << i << ' ';
        }
        cout << '\n';
    } while (prev_permutation(is_used1.begin(),is_used1.end()));

    return 0;
}