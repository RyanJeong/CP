// https://www.acmicpc.net/problem/16472
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    string str;
    cin>>str;

    int low = 0;
    int high = 0;
    int cnt = 0;
    int res = 0;
    vector<int> freq(26);
    while (low<=high) {
        if (cnt>n) {
            int idx = str[low++]-'a';
            --freq[idx];
            if (!freq[idx]) {
                --cnt;
            }
        }
        else {
            res=max(res,high-low);
            if (high==str.size()) {
                break;
            }

            int idx = str[high++]-'a';
            if (!freq[idx]) {
                ++cnt;
            }
            ++freq[idx];
        }
    }
    cout << res;

    return 0;
}
