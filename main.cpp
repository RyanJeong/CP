// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

void quicksort(int, int);
void swap(int, int);

int arr[1'000'000];

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	for (int i = 0; i<n; ++i) {
		cin>>arr[i];
	}

    quicksort(0,n);    
	for (int i = 0; i<n; ++i) {
		cout << arr[i] << '\n';
	}

	return 0;
}

void quicksort(int left, int right)
{
    if (left>=right) {
        
        return;
    }

    swap(left,(left+right)/2);
    int last = left;
    for (int i = left+1; i<right; ++i) {
        if (arr[left]>arr[i]) {
            swap(++last,i);
        }
    }
    swap(left,last);
    quicksort(left,last);
    quicksort(last+1,right);

    return;
}

void swap(int i, int j)
{
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

    return;
}