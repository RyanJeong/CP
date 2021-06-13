// http://icpc.me/2751
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int temp[1000001];

void prepare(int, int);
void merge(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;    
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    prepare(0,n);

    for (int i = 0; i<n; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}

void prepare(int low, int high)
{
    if (high-low==1) {

        return;
    }

    int mid = (low+high)/2;

    prepare(low,mid);
    prepare(mid,high);
    merge(low,high);

    return;
}

void merge(int low, int high)
{
    int mid = (low+high)/2;
    int i_low = low;
    int i_high = mid;

    for (int i = low; i<high; ++i) {
        if (i_low==mid) {
            temp[i]=arr[i_high++];
        } 
        else if (i_high==high) {
            temp[i]=arr[i_low++];
        } 
        else if (arr[i_low]<arr[i_high]) {
            temp[i]=arr[i_low++];
        } 
        else { // arr[i_low] > arr[i_high]
            temp[i]=arr[i_high++];
        }
    }
    for (int i = low; i<high; ++i) {
        arr[i]=temp[i];
    }

    return;
}