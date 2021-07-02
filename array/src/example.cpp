#include <bits/stdc++.h>

using namespace std;

int insert(int[], const int, int&, int, int);
int erase(int[], const int, int&, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int cap = 10;
    // An array that can store only positive numbers;
    int arr[cap] = { 1, 2, 4, 8, 16, 32 };
    int len = 0;
    for (int i = 0; i<cap; ++i) {
        if (arr[i]) {
            ++len;
        }
    }
    cout << "capacity: " << cap << ", length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 1 2 4 8 16 32

    // 1. insert
    insert(arr,cap,len,0,50);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 1 2 4 8 16 32
    insert(arr,cap,len,len,60);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 1 2 4 8 16 32 60

    // 2. erase
    erase(arr,cap,len,1);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 2 4 8 16 32 60
    erase(arr,cap,len,len);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 2 4 8 16 32

    return 0;
}

int insert(int arr[],const int cap,int& len,int idx,int val)
{
    if (len==cap) {
        
        return 0;
    }
    if (idx>len) {

        return 0;
    }
    for (int i = len; i>idx; --i) {
        arr[i]=arr[i-1];
    }
    arr[idx]=val;
    ++len;

    return val;
}

int erase(int arr[],const int cap,int& len,int idx)
{
    if (len==0) {

        return 0;
    }
    if (idx>len) {

        return 0;
    }
    --len;
    int val = arr[idx];
    for (int i = idx; i<len; ++i) {
        arr[i]=arr[i+1];
    }

    return val;
}