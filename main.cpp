// https://www.acmicpc.net/problem/10775
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int g;
    cin>>g;
    for (int i = 0; i<=g; ++i) {
        parent.push_back(i);
    }

	int p;
	cin>>p;
	int res=0;
    for (int i = 1; i<=p; ++i) {
        int gate;
		cin>>gate;
		int cur = find(gate);
		if (!cur) {
			break;
		}
		merge(cur,cur-1);
		++res;
    }
	cout << res;

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
    parent[u]=v;

    return;
}