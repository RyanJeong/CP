// http://icpc.me/10816
// lowest: 중복된 수 중 가장 왼쪽에 있는 인덱스
// highest: 중복된 수 중 가장 오른쪽 바로 다음에 있는 인덱스
#include <bits/stdc++.h>

using namespace std;

int arr[500005];

int lowest(int target, int len);
int highest(int target, int len);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    } 
    int m;
    cin>>m;

    sort(arr,arr+n);
    while (m--) {
        int t;
        cin>>t;

        cout << highest(t,n)-lowest(t,n) << ' ';
    }    

    return 0;
}

// if target: 4
// 1 2 3 '4' 4 4 4 5 6
int lowest(int target, int len)
{
    int low = 0;
    int high = len;

    while (low<high) {
        int mid = (low+high)/2;

        if (arr[mid]>=target) {
            high=mid;
        } 
        else {
            low=mid+1;
        }
    }

    return low;
}

// if target: 4
// 1 2 3 4 4 4 4 '5' 6
int highest(int target, int len)
{
    int low = 0;
    int high = len;

    while (low<high) {
        int mid = (low+high)/2;

        if (arr[mid] <= target) {
            low=mid+1;
        } 
        else {
            high=mid;
        }
    }

    return low;
}