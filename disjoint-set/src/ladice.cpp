// https://www.acmicpc.net/problem/9938
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent;
vector<bool> is_filled;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int l;
    cin>>l;
    parent=vector<int>(l+1);
    for (int i = 1; i<=l; ++i) {
        parent[i]=i;
    }
    is_filled=vector<bool>(l+1,false);
    while (n--) {
        int a, b;
        cin>>a>>b;
        if (!is_filled[a]) {
            is_filled[a]=true;
            merge(a,b);
        }
        else if (!is_filled[b]) {
            is_filled[b]=true;
            merge(b,a);
        }
        else if (!is_filled[find(a)]) {
            is_filled[find(a)]=true;
            merge(a,b);
        }
        else if (!is_filled[find(b)]) {
            is_filled[find(b)]=true;
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
    parent[u]=v;

    return;
}