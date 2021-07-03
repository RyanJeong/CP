// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

// O(n) - divide
// 1+2+...+2^k = 2n-1, O(n)
// n = 8 -> k = 2
void mergesort(int, int);
// O(n log n) - conquer
// n x k, k = lg (2n-1), O(n lg n)
void merge(int, int);

int arr[1'000'000];
int tmp[1'000'000];

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    mergesort(0,n);    
    for (int i = 0; i<n; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}

void mergesort(int s, int t)
{
    if (s+1==t) {
        
        return;
    }
    int mid = (s+t)/2;
    mergesort(s,mid);
    mergesort(mid,t);
    merge(s,t);
}

void merge(int s, int t)
{
    int mid = (s+t)/2;
    int idx1 = s; // [s, mid)
    int idx2 = mid; // [mid, t)
    for (int i = s; i<t; ++i) {
        if (idx1==mid) {
            tmp[i]=arr[idx2++];
        }
        else if (idx2==t) {
            tmp[i]=arr[idx1++];
        }
        else if (arr[idx1]<arr[idx2]) {
            tmp[i]=arr[idx1++];
        }
        else { // arr[idx1]>=arr[idx2]
            tmp[i]=arr[idx2++];
        }
    }
    // copy to original array
    for (int i = s; i<t; ++i) {
        arr[i]=tmp[i];
    }
    
    return;
}