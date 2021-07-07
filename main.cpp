// https://www.acmicpc.net/problem/12877
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
	// 1~n    : Group A
	// n+1~2n : Group B
	// 2n+1~3n: Group C
	parent=vector<int>(3*n+1);
	for (int i = 0; i<=3*n; ++i) {
		parent[i]=i; 
	}
	level=vector<int>(3*n+1,1);
	int cnt = 0;
	for (int i = 1; i<=k; ++i) {
		int t, x, y;
		cin>>t>>x>>y;
		if (x<1 || x>n) {
			++cnt;
			continue;
		}
		if (y<1 || y>n) {
			++cnt;
			continue;
		}
		if (t==1) { // t==1
			if (find(x)==find(y+n) || find(x)==find(y+n+n)) {
				++cnt;
			}
			else {
				merge(x,y); // Group A
				merge(x+n,y+n); // Group B
				merge(x+n+n,y+n+n); // Group C
			}
		}
		else { // t==2
			if (find(x)==find(y) || find(x)==find(y+n+n)) {
				++cnt;
			}
			else {
				merge(x,y+n); // A->B
				merge(x+n,y+n+n); // B->C
				merge(x+n+n,y); // C->A
			}
		}
	}
	cout << cnt;

    return 0;
}

int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }

    return parent[u]=find(parent[u]);
}

void merge(int u, int v)
{
    u=find(u); 
    v=find(v); 
    if (u==v) {
        
        return; 
    }
    if (level[u]>level[v]) {
        swap(u,v); 
    }
    parent[u]=v;
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return;
}