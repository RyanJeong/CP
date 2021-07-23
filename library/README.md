* 2차원 배열 전환
...

* [CCW](./src/ccw.cpp)
```c++
// 1: ccw, -1: cw, 0: on the line
int is_ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	long long u1 = b.first-a.first;
	long long v1 = b.second-a.second;
	long long u2 = c.first-b.first;
	long long v2 = c.second-b.second;
	long long tmp = u1*v2-u2*v1;

	return ((tmp>0) ? 1 : (tmp<0) ? -1 : 0);
}
```

* [LIS](./src/lis.cpp)
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }

    vector<int> lis;
    lis.push_back(v[1]);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
        }
    }
    cout << lis.size();

    return 0;
}
```

* [Outer Product](./src/outer_product.cpp)
```c++
typedef pair<long long, long long> Point;

long long outer_product(Point u, Point v)
{

    return u.first*v.second-u.second*v.first;
}
```

* [`nth_element`](./src/nth_element.cpp)
```c++
#include <algorithm>
#include <vector>

using namespace std;

int kth(vector<int>& a, int k) 
{
	nth_element(a.begin(),a.begin()+k-1,a.end()); // 0-based
	
    return a[k-1];
}
```