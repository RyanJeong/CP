// https://www.acmicpc.net/problem/4195
#include <bits/stdc++.h>

using namespace std;

int find(int);
int merge(int, int);

vector<int> parent, level, n_friend;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    while (n--) {
        int f;
        cin>>f;
        parent=vector<int>(f*2);
        for (int i = 0; i<f*2; ++i) {
            parent[i]=i;
        }
        level=vector<int>(f*2,1);
        n_friend=vector<int>(f*2,1);
        map<string, int> m;
        int idx = 0;
        while (f--) {
            string str1;
            cin>>str1;
            if (m.find(str1)==m.end()) {
                m[str1]=idx++;
            }
            string str2;
            cin>>str2;
            if (m.find(str2)==m.end()) {
                m[str2]=idx++;
            }
            cout << merge(m[str1],m[str2]) << '\n';
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

int merge(int u, int v)
{
    u=find(u); 
    v=find(v); 
    if (u==v) {

        return n_friend[v]; 
    }
    if (level[u]>level[v]) {
        swap(u,v); 
    }
    parent[u]=v;
    n_friend[v]+=n_friend[u];
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return n_friend[v]; 
}
