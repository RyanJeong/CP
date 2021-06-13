// http://icpc.me/1920
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }
    int t;
    cin>>t;

    sort(v.begin(),v.end());
    while (t--) {
        int low = 0;
        int high = v.size()-1;
        int target;
        cin>>target;

        while (low<=high) {
            int mid = (low+high)/2;

            if (v[mid]>target) {
                high=mid-1;
            } 
            else if (v[mid]<target) {
                low=mid+1;
            } 
            else {
                break;
            }
        }
        cout << ((low > high) ? 0 : 1) << '\n';
    }

    return 0;
}