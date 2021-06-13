// http://icpc.me/11054
#include <bits/stdc++.h>

using namespace std;

int arr[1'002];
int r_d[1'002];
int l_d[1'002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 1; i<=n; ++i) {
        int temp = 0;
        cin>>arr[i];

        for (int j = 1; j<i; ++j) {
            if (arr[j]<arr[i]) {
                temp=max(temp,l_d[j]);
            }
        }
        l_d[i]=temp+1;
    }
    for (int i = n; i>0; --i) {
        int temp = 0;

        for (int j = n; i<j; --j) {
            if (arr[i]>arr[j]) {
                temp=max(temp,r_d[j]);
            }
        }
        r_d[i]=temp+1;
    }
    int mid = 0;

    for (int i = 1; i<=n; ++i) {
        l_d[i]+=r_d[i];
        mid=max(mid,l_d[i]); 
    }
    cout << mid - 1;

    return 0;
}