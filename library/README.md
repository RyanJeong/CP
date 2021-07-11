* 2차원 배열 전환
...

* Outer Product
```c++
typedef pair<long long, long long> Point;

long long outer_product(Point u, Point v)
{

    return u.first*v.second-u.second*v.first;
}
```

* CCW
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