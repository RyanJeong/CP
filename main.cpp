// https://www.acmicpc.net/problem/9938
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int l;
    cin>>l;
    vector<bool> is_used(l+1,false);
    parent=vector<int>(l+1);
    for (int i = 1; i<=l; ++i) {
        parent[i]=i;
    }
    level=vector<int>(l+1,1);
    while (n--) {
        int a, b;
        cin>>a>>b;
        if (!is_used[a]) {
            is_used[a]=true;
            merge(a,b);
        }
        else if (!is_used[b]) {
            is_used[b]=true;
            merge(b,a);
        }
        else if (!is_used[find(a)]) {
            is_used[find(a)]=true;
            merge(a,b);
        }
        else if (!is_used[find(b)]) {
            is_used[find(b)]=true;
            merge(b,a);
        }
        else {
            cout << "SMECE" << '\n';
        }
    }

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
    cout << "LADICA" << '\n';
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