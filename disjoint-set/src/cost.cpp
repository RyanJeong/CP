// https://www.acmicpc.net/problem/10775
/*
조건
    1. 서로 다른 두 정점 u,v에 대하여, Cost(u,v)는 다음에서 제거되는 
    간선들의 가중치 합이다: u와 v사이의 경로가 있으면 이 그래프의 
    최소 가중치 간선을 그래프에서 제거한다. 이 과정을 u와 v사이의 
    경로가 없을 때까지 반복한다.
    2. 간선에 가중치가 있는 그래프가 주어질 때, u < v인 모든 두 정점 
    u, v에 대한 Cost(u,v)들의 총 합을 구하라.

위 조건을 뒤집어 생각하면, 아래와 논리적으로 동치관계다.
    서로 다른 두 정점 u,v에 대하여, 간선 가중치가 높은 순서대로 간선을 
    새로 생성한다. 이때 Cost(u,v)는 아직 생성되지 않은 간선들의 가중치와 
    방금 추가된 간선의 가중치의 합이다. 또한 u < v인 모든 두 정점 u, v에
    대한 Cost(u,v)들의 총 합을 구한다는 조건을 만족해야 한다. 

    1-(7)-2'''(2)'''3-(5)-4

    괄호에 둘러쌓인 숫자는 가중치, 일반 숫자는 정점, -는 이미 만들어진 간선,
    '''는 방금 생성된 간선이라고 가정하자. 이때 방금 만들어진 간선을 제거할 
    수 있는 경우는 (1,2), (1,3), (2,3), (2,4) 총 네 가지다.
    이를 일반화하면, 서로 독립되어 있던 그래프의 크기를 이용하면 모든 경우에서의
    아직 생성되지 않은 간선들의 가중치+방금 추가된 간선의 가중치 합을 계산할 수
    있다. 
*/
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent;
vector<long long> size;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    parent=vector<int>(n+1);
    for (int i = 1; i<=n; ++i) {
        parent[i]=i;
    }
    size=vector<long long>(n+1,1);
    vector<pair<int, pair<int, int>>> info; // w, (x,y)
    long long total = 0; //1+2+...+99,999+100,000
                   // 100,101*100,000/2
                   // 5,000,050,000
    for (int i = 1; i<=m; ++i) {
        int x, y, w;
        cin>>x>>y>>w;
        info.push_back({w,make_pair(x,y)});
        total+=w;
    }
    sort(info.begin(),info.end());
    long long res = 0;
    while (!info.empty()) {
        auto cur = info.back();
        info.pop_back();
        int x = cur.second.first;
        int y = cur.second.second;
        int w = cur.first;

        // 서로 분리된 그래프
        if (find(x)!=find(y)) {
            long long sz = size[find(x)]*size[find(y)]%1'000'000'000;
            res+=(sz*total)%1'000'000'000;
            res%=1'000'000'000;
            merge(find(x),find(y));
        }
        total-=w;
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
    size[v]+=size[u];

    return;
}
