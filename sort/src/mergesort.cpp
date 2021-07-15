// https://www.acmicpc.net/submit/2751
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;
        pq.push(temp);
    }

    vector<int> v(n);
    v.reserve(n);
    for (int i = 0; i<n; ++i) {
        v[i]=pq.top();
        pq.pop();
    }
    for (int i : v) {
        cout << i << '\n';
    }

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

vector<int> arr = {423,25,245,32,1,63,-33,-2};
vector<int> tmp;

void merge_sort(int, int);
void merge(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n = arr.size();
	tmp.reserve(n);
	merge_sort(0,n);
	for (int i : arr) {
		cout << i << ' ';
	}

    return 0;
}

void merge_sort(int low, int high)
{
	if (low+1==high) {
		
		return; 
	}
	int mid = (low+high)/2;
	merge_sort(low,mid);
	merge_sort(mid,high); 
	merge(low,high); 

	return;
}

void merge(int low, int high)
{
	int mid = (low+high)/2;
	int left = low;
	int right = mid;
	for(int i = low; i<high; ++i) {
		if (left==mid) {
			tmp[i]=arr[right++];
		}
		else if (right==high) {
			tmp[i]=arr[left++];
		}
		else if (arr[left]<arr[right]) {
			tmp[i]=arr[left++];
		}
		else {
			tmp[i]=arr[right++];
		}
	}
	for (int i = low; i<high; ++i) {
		arr[i]=tmp[i];
	}

	return;
}
*/