// https://www.acmicpc.net/problem/1253
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    sort(v.begin()+1,v.end()); // 1-based

    int res = 0;
    for (int i = 1; i<=n; ++i) {
        int target = v[i];
        int low = 1;
        int high = n;
        while (low<high) {
            int tmp = v[low]+v[high];
            if (target==tmp) {
                if (low==i) {
                    ++low;
                }
                else if (high==i) {
                    --high;
                }
                else {
                    ++res;
                    break;
                }
            }
            else if (target>tmp) {
                ++low;
            }
            else if (target<tmp) {
                --high;
            }
        }
    }
    cout << res;

    return 0;
}
