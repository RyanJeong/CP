// https://www.acmicpc.net/problem/2220
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    static int arr[100'001];
    int n;
    cin>>n;

    /*
        1

        1         2
       2    ->   1

        2       2       3
       1 3  -> 3 1 ->  2 1
    */
    arr[1]=1;
    for (int i = 2; i<=n; ++i) {
        arr[i]=i;
        swap(arr[i-1],arr[i]);
        for (int j = i-1; j>1; j/=2) {
            swap(arr[j],arr[j/2]);
        }
    }
    for (int i = 1; i<=n; ++i) {
        cout << arr[i] << ' ';
    }

    return 0;
}